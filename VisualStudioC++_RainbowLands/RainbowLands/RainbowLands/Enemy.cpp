#include "Enemy.h"

using namespace godot;
Enemy::Enemy() 
{
	_speed = 100;
	_health = 3;
	_damage = 1;
}

Enemy::~Enemy()
{
}

void Enemy::_register_methods()
{
	register_method((char*)"_physics_process", &Enemy::_physics_process);
	register_method((char*)"_init", &Enemy::_init);
	register_method((char*)"_ready", &Enemy::_ready);
	register_property<Enemy, int>("Health", &Enemy::_health, 3);
	register_property<Enemy, int>("Speed", &Enemy::_speed, 100);
	register_property<Enemy, int>("Damage", &Enemy::_damage, 1);
	register_method((char*)"_on_Area2D_area_entered", &Enemy::_on_Area2D_area_entered);
}

void Enemy::_init()
{
	_level_manager = LevelManager::get_singleton();
}

void Enemy::_ready()
{

}

void Enemy::_physics_process(float delta)
{
	set_offset(get_offset() + _speed * delta);

	if (get_unit_offset() >= 1)
	{
		_level_manager->_mob_got_through(_damage);
			queue_free();
	}
}

void Enemy::_on_Area2D_area_entered(Area2D* _other_area)
{
	if (_other_area->is_in_group("Projectile"))
	{
		Godot::print("Got hit by projectile");
		_other_area->queue_free();
		_health -= 1;
		if (_health <= 0)
		{
			//add money to wallet (!)
			call_deferred("queue_free");
		}
	}
}