#include "AreaDamage.h"

using namespace godot;

AreaDamage::AreaDamage()
{
	target = nullptr;
	speed = 400;
	damage = 1;
	tickTime = 0.2;
	selfDestructTime = 3;

	canMove = true;

	pathVFX = "res://TD/Projectiles/particles/BladeSparks.tscn";
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

	register_method((char*)"OnSelfDestructTimeout", &AreaDamage::OnSelfDestructTimeout);
	register_method((char*)"SetTarget", &AreaDamage::SetTarget);

	register_property<AreaDamage, int>("Speed", &AreaDamage::speed, 400);
	register_property<AreaDamage, int>("Damage", &AreaDamage::damage, 1);
	register_property<AreaDamage, double>("TickTime", &AreaDamage::tickTime, 0.2);
	register_property<AreaDamage, double>("SelfDestructTime", &AreaDamage::selfDestructTime, 3);
	register_property<AreaDamage, String>("pathVFX", &AreaDamage::pathVFX, "res://TD/Projectiles/particles/BladeSparks.tscn");
}

void AreaDamage::_init()
{
}

void AreaDamage::_ready()
{
	loader = ResourceLoader::get_singleton();
	refVFX = loader->load(pathVFX);
	velocity = { 0, 0 };
	selfDestruct = cast_to<Timer>(get_node("SelfDestruct"));
	selfDestruct->set_wait_time(selfDestructTime);
	selfDestruct->start();
	cooldownTimePassed = tickTime;
}

void AreaDamage::_physics_process(float delta)
{
	set_rotation(get_rotation() + (900 * (pi/180) * delta));

	if (cooldownTimePassed <= tickTime)
		cooldownTimePassed += delta;

	if (canMove)
	{
		velocity = ((targetPosition - get_position()).normalized() * speed) * delta;
		if ((get_position() - targetPosition).length() < velocity.length()) // <= Vector2::ONE
		{
			canMove = false;
		}

		set_position(get_position() + velocity);
	}

	enemies = get_overlapping_areas();

	if (enemies.size() > 0)
	{
		if (cooldownTimePassed >= tickTime)
		{
			cooldownTimePassed = 0;
			for (int i = 0; i < enemies.size(); i++)
			{
				if (cast_to<Area2D>(enemies[i])->is_in_group("Enemy"))
				{
					cast_to<Enemy>(cast_to<Area2D>(enemies[i])->get_parent())->TakeDamage(damage);

					VFX = cast_to<Particles2D>(refVFX->instance());
					VFX->set_position(cast_to<Area2D>(enemies[i])->get_global_transform().get_origin());
					VFX->set_rotation(this->get_rotation());
					get_node("/root/main/particles")->add_child(VFX);
					VFX->set_emitting(true);
				}
			}
		}
	}
}

void AreaDamage::OnSelfDestructTimeout()
{
	queue_free();
}

void AreaDamage::SetTarget(PathFollow2D* _target)
{
	target = _target;
	if (target != nullptr)
		targetPosition = target->get_global_transform().get_origin();
}
