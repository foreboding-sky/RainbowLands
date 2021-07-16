#include "AreaDamage.h"

using namespace godot;

AreaDamage::AreaDamage()
{
	target = nullptr;
	speed = 400;
	damage = 1;
	tickTime = 0.2;
}

AreaDamage::~AreaDamage()
{
	target = nullptr;
	delete target;
}

void AreaDamage::_register_methods()
{
	register_method((char*)"_physics_process", &AreaDamage::_physics_process);
	register_method((char*)"_init", &AreaDamage::_init);
	register_method((char*)"_ready", &AreaDamage::_ready);

	register_method((char*)"OnEnemyAreaEntered", &AreaDamage::OnEnemyAreaEntered);
	register_method((char*)"SetTarget", &AreaDamage::SetTarget);

	register_property<AreaDamage, int>("Speed", &AreaDamage::speed, 400);
	register_property<AreaDamage, int>("Damage", &AreaDamage::damage, 1);
	register_property<AreaDamage, double>("TickTime", &AreaDamage::tickTime, 0.2);
}

void AreaDamage::_init()
{
}

void AreaDamage::_ready()
{
	velocity = { 0, 0 };
	selfDestruct = cast_to<Timer>(get_node("SelfDestruct"));
	selfDestruct->set_wait_time(5);
	selfDestruct->start();
	cooldownTimePassed = tickTime;
}

void AreaDamage::_physics_process(float delta)
{
	set_rotation(300 * (pi / 180) * delta);

	if (cooldownTimePassed <= tickTime)
		cooldownTimePassed += delta;

	if (canMove)
	{
		if (target != nullptr && get_node_or_null(targetPath) != NULL)
		{
			velocity = ((target->get_global_transform().get_origin() - get_position()).normalized() * speed);
		}

		set_position(get_position() + velocity * delta);
	}

	if (canDealDamage)
	{
		if (cooldownTimePassed >= tickTime)
		{
			cooldownTimePassed = 0;
			enemies = get_overlapping_areas();
			for (int i = 0; i < enemies.size(); i++)
			{
				if (cast_to<Area2D>(enemies[i])->is_in_group("Enemy"))
				{
					cast_to<Enemy>(cast_to<Area2D>(enemies[i])->get_parent())->TakeDamage(damage);
				}
			}
		}
	}
}

void godot::AreaDamage::OnEnemyAreaEntered(Area2D* otherArea)
{
	if (otherArea->is_in_group("Enemy"))
	{
		canDealDamage = true;
		canMove = false;
	}
}

void AreaDamage::SetTarget(PathFollow2D* _target)
{
	target = _target;
	if (target != nullptr)
		targetPath = target->get_path();
}
