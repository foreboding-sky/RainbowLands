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
	register_method((char*)"TakeDamage", &Enemy::TakeDamage);
}

void Enemy::_init()
{
	levelManager = LevelManager::get_singleton();
}

void Enemy::_ready()
{
	ScaleStats(1.0f + levelManager->waveCounter / 10.0f);
}

void godot::Enemy::ScaleStats(float value)
{
	health *= value;
	speed *= 0.5 + (value/4.0f);
}

void godot::Enemy::TakeDamage(int damage)
{
	health -= damage;
	if (health <= 0)
	{
		levelManager->MobDefeated(this->damage);
		queue_free();
	}
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
