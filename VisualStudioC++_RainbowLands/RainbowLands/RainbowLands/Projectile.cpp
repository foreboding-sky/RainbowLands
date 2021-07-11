#include "Projectile.h"

using namespace godot;
Projectile::Projectile()
{
	target = nullptr;
}

Projectile::~Projectile()
{
	target = nullptr;
}

void Projectile::_register_methods()
{
	register_method((char*)"_physics_process", &Projectile::_physics_process);
	register_method((char*)"_init", &Projectile::_init);
	register_method((char*)"_ready", &Projectile::_ready);

	register_method((char*)"SetTarget", &Projectile::SetTarget);
}

void Projectile::_init()
{
}

void Projectile::_ready()
{
	velocity = { 0, 0 };
	speed = 300;
}

void Projectile::_physics_process(float delta)
{
	if (target != nullptr && get_node_or_null(targetPath) != NULL)
	{
		velocity = ((target->get_global_transform().get_origin() - get_position()).normalized() * speed);
		set_position(get_position() + velocity * delta);
		set_rotation(velocity.angle());
	}
	else
	{
		Godot::print("No target");
		queue_free();
	}
}

void Projectile::SetTarget(PathFollow2D* _target)
{
	target = _target;
	if(target != nullptr)
		targetPath = target->get_path();
}
