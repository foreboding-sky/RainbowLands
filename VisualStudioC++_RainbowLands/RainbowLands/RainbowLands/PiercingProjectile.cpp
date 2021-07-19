#include "PiercingProjectile.h"

using namespace godot;
PiercingProjectile::PiercingProjectile()
{
	target = nullptr;
	speed = 600;
	damage = 2;
	pathVFX = "res://TD/Projectiles/particles/Slash.tscn";
}

PiercingProjectile::~PiercingProjectile()
{
	target = nullptr;
	delete target;
}

void PiercingProjectile::_register_methods()
{
	register_method((char*)"_physics_process", &PiercingProjectile::_physics_process);
	register_method((char*)"_init", &PiercingProjectile::_init);
	register_method((char*)"_ready", &PiercingProjectile::_ready);

	register_method((char*)"OnSelfDestructTimeout", &PiercingProjectile::OnSelfDestructTimeout);
	register_method((char*)"OnEnemyAreaEntered", &PiercingProjectile::OnEnemyAreaEntered);
	register_method((char*)"SetTarget", &PiercingProjectile::SetTarget);

	register_property<PiercingProjectile, int>("Speed", &PiercingProjectile::speed, 600);
	register_property<PiercingProjectile, int>("Damage", &PiercingProjectile::damage, 2);
	register_property<PiercingProjectile, String>("pathVFX", &PiercingProjectile::pathVFX, "res://TD/Projectiles/particles/Slash.tscn");
}

void PiercingProjectile::_init()
{
}

void PiercingProjectile::_ready()
{
	loader = ResourceLoader::get_singleton();
	refVFX = loader->load(pathVFX);
	velocity = { 0, 0 };
	selfDestruct = cast_to<Timer>(get_node("SelfDestruct"));
	selfDestruct->set_wait_time(2);
	selfDestruct->start();
}

void PiercingProjectile::_physics_process(float delta)
{
	velocity = (targetDirection * speed);
	set_position(get_position() + velocity * delta);
	set_rotation(velocity.angle());
}

void godot::PiercingProjectile::OnSelfDestructTimeout()
{
	queue_free();
}

void godot::PiercingProjectile::OnEnemyAreaEntered(Area2D* otherArea)
{
	if (otherArea->is_in_group("Enemy"))
	{
		cast_to<Enemy>(otherArea->get_parent())->TakeDamage(damage);

		VFX = cast_to<Particles2D>(refVFX->instance());
		VFX->set_position(otherArea->get_global_transform().get_origin());
		VFX->set_rotation(this->get_rotation() + 1.5708);
		get_node("/root/main/particles")->add_child(VFX);
		VFX->set_emitting(true);
	}
}

void PiercingProjectile::SetTarget(PathFollow2D* _target)
{
	target = _target;
	if (target != nullptr)
		targetDirection = (target->get_global_transform().get_origin() - get_position()).normalized();
	if (targetDirection == Vector2::ZERO)
		targetDirection = Vector2::UP;
}
