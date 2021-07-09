#include "Projectile.h"

using namespace godot;
Projectile::Projectile()
{
	_target = nullptr;
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

	register_method((char*)"_set_target", &Projectile::_set_target);
}

void Projectile::_init()
{
}

void Projectile::_ready()
{
	_velocity = { 0, 0 };
	_speed = 300;
}

void Projectile::_physics_process(float delta)
{
	
	if (_target->get_instance_id())
	{
		_velocity = ((_target->get_global_transform().get_origin() - get_position()).normalized() * _speed);
		set_position(get_position() + _velocity * delta);
		set_rotation(_velocity.angle());
	}
	else
	{
		Godot::print("No target");
		queue_free();
	}
}

void Projectile::_set_target(PathFollow2D* target)
{
	_target = target;
}
