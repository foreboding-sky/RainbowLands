#include "Enemy.h"

using namespace godot;
Enemy::Enemy() 
{
	speed = 100;
	health = 3;
	damage = 1;
}

Enemy::~Enemy()
{
}

void Enemy::_register_methods()
{
	register_method((char*)"_physics_process", &Enemy::_physics_process);
	register_method((char*)"_init", &Enemy::_init);
	register_method((char*)"_ready", &Enemy::_ready);
	register_property<Enemy, int>("Health", &Enemy::health, 3);
	register_property<Enemy, int>("Speed", &Enemy::speed, 100);
	register_property<Enemy, int>("Damage", &Enemy::damage, 1);
	register_method((char*)"_on_Area2D_area_entered", &Enemy::_on_Area2D_area_entered);
}

void Enemy::_init()
{
	levelManager = LevelManager::get_singleton();
}

void Enemy::_ready()
{

}

void Enemy::_physics_process(float delta)
{
	set_offset(get_offset() + speed * delta);

	if (get_unit_offset() >= 1)
	{
		levelManager->MobGotThrough(damage);
			queue_free();
	}
}

void Enemy::_on_Area2D_area_entered(Area2D* _other_area)
{
	if (_other_area->is_in_group("Projectile"))
	{
		Godot::print("Got hit by projectile");
		_other_area->queue_free();
		health -= 1;
		if (health <= 0)
		{	
			queue_free();
			levelManager->AddCurrency(damage);
		}
	}
}