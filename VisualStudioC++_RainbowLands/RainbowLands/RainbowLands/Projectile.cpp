#include "Projectile.h"

using namespace godot;
Projectile::Projectile()
{
}

Projectile::~Projectile()
{
	_target = nullptr;
}

void Projectile::_register_methods()
{
	register_method((char*)"_physics_process", &Projectile::_physics_process);
	register_method((char*)"_init", &Projectile::_init);
	register_method((char*)"_ready", &Projectile::_ready);
}

void Projectile::_init()
{
}

void Projectile::_ready()
{
	_velocity = { 0, 0 };
	_speed = 100;
	_target = nullptr;
}

void Projectile::_physics_process(float delta)
{
	if (_target != nullptr)
	{
		_velocity = ((_target->get_global_transform().get_origin() - get_position()).normalized() * _speed);
		set_position(_velocity * delta);
		set_rotation(_velocity.angle());
	}
	else
	{
		queue_free();
	}
}

void Projectile::_set_target(PathFollow2D* target)
{
	_target = target;
}
