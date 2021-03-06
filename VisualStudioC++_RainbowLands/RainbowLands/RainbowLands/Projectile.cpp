#include "Projectile.h"

using namespace godot;
Projectile::Projectile()
{
	target = nullptr;
	hasTarget = false;
	speed = 400;
	damage = 1;
	pathVFX = "res://TD/Projectiles/particles/PlasmaExplosion.tscn";
}

Projectile::~Projectile()
{
	target = nullptr;
	delete target;
}

void Projectile::_register_methods()
{
	register_method((char*)"_physics_process", &Projectile::_physics_process);
	register_method((char*)"_init", &Projectile::_init);
	register_method((char*)"_ready", &Projectile::_ready);

	register_method((char*)"OnEnemyAreaEntered", &Projectile::OnEnemyAreaEntered);
	register_method((char*)"SetTarget", &Projectile::SetTarget);	
	register_method((char*)"OnSelfDestructTimeout", &Projectile::OnSelfDestructTimeout);

	register_property<Projectile, int>("Speed", &Projectile::speed, 400);
	register_property<Projectile, int>("Damage", &Projectile::damage, 1);
	register_property<Projectile, String>("pathVFX", &Projectile::pathVFX, "res://TD/Projectiles/particles/PlasmaExplosion.tscn");
}

void Projectile::_init()
{
}

void Projectile::_ready()
{
	loader = ResourceLoader::get_singleton();
	refVFX = loader->load(pathVFX);
	velocity = { 0, 0 };
	selfDestruct = cast_to<Timer>(get_node("SelfDestruct"));
	selfDestruct->set_wait_time(5);
	selfDestruct->start();
}

void Projectile::_physics_process(float delta)
{
	if (target != nullptr && get_node_or_null(targetPath) != NULL)
	{
		velocity = ((target->get_global_transform().get_origin() - get_position()).normalized() * speed);

	}
	set_position(get_position() + velocity * delta);
	set_rotation(velocity.angle());
}

void godot::Projectile::OnEnemyAreaEntered(Area2D* otherArea)
{
	if (otherArea->is_in_group("Enemy"))
	{

		cast_to<Enemy>(otherArea->get_parent())->TakeDamage(damage);

		VFX = cast_to<Particles2D>(refVFX->instance());
		VFX->set_position(this->get_position());
		VFX->set_rotation(this->get_rotation());
		get_node("/root/main/particles")->add_child(VFX);
		VFX->set_emitting(true);

		queue_free();
	}
}

void godot::Projectile::OnSelfDestructTimeout()
{
	queue_free();
}

void Projectile::SetTarget(PathFollow2D* _target)
{
	
	target = _target;
	if (target != nullptr)
	{
		hasTarget = true;
		targetPath = target->get_path();
	}
}
