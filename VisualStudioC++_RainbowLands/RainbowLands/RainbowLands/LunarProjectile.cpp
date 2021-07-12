#include "LunarProjectile.h"

using namespace godot;
LunarProjectile::LunarProjectile()
{
	target = nullptr;
}

LunarProjectile::~LunarProjectile()
{
	target = nullptr;
	delete target;
}

void LunarProjectile::_register_methods()
{
	register_method((char*)"_physics_process", &LunarProjectile::_physics_process);
	register_method((char*)"_init", &LunarProjectile::_init);
	register_method((char*)"_ready", &LunarProjectile::_ready);

	register_method((char*)"OnSelfDestructTimeout", &LunarProjectile::OnSelfDestructTimeout);
	register_method((char*)"OnEnemyAreaEntered", &LunarProjectile::OnEnemyAreaEntered);
	register_method((char*)"SetTarget", &LunarProjectile::SetTarget);
}

void LunarProjectile::_init()
{
}

void LunarProjectile::_ready()
{
	velocity = { 0, 0 };
	speed = 600;
	damage = 2;
	selfDestruct = cast_to<Timer>(get_node("SelfDestruct"));
	selfDestruct->set_wait_time(2);
	selfDestruct->start();
}

void LunarProjectile::_physics_process(float delta)
{
	velocity = (targetDirection * speed);
	set_position(get_position() + velocity * delta);
	set_rotation(velocity.angle());
}

void godot::LunarProjectile::OnSelfDestructTimeout()
{
	queue_free();
}

void godot::LunarProjectile::OnEnemyAreaEntered(Area2D* otherArea)
{
	if (otherArea->is_in_group("Enemy"))
	{
		cast_to<Enemy>(otherArea->get_parent())->TakeDamage(damage);
	}
}

void LunarProjectile::SetTarget(PathFollow2D* _target)
{
	target = _target;
	if (target != nullptr)
		targetDirection = (target->get_global_transform().get_origin() - get_position()).normalized();
}
