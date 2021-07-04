#include "Enemy.h"

using namespace godot;
Enemy::Enemy() 
{
	_health = 3;
	_speed = 100;
}
Enemy::~Enemy()
{
}
void Enemy::_physics_process(float delta)
{
	set_offset(get_offset() + _speed * delta);

	if (get_unit_offset() >= 1)
		queue_free();
}
void Enemy::_init() 
{
}
void Enemy::_ready()
{
}
void Enemy::_register_methods()
{
	register_method((char*)"_physics_process", &Enemy::_physics_process);
	register_method((char*)"_init", &Enemy::_init);
	register_method((char*)"_ready", &Enemy::_ready);
}