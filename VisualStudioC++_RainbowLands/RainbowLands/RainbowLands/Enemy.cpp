#include "Enemy.h"

using namespace godot;
Enemy::Enemy() 
{
	speed = 100;
	maxHealth = 3;
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
	register_property<Enemy, int>("MaxHealth", &Enemy::maxHealth, 3);
	register_property<Enemy, int>("Speed", &Enemy::speed, 100);
	register_property<Enemy, int>("Damage", &Enemy::damage, 1);
	register_method((char*)"TakeDamage", &Enemy::TakeDamage);
	register_method("_hovered", &Enemy::OnMouseHovered);
	register_method("_left", &Enemy::OnMouseLeft);
}

void Enemy::_init()
{
	levelManager = LevelManager::get_singleton();

}

void Enemy::_ready()
{
	loader = ResourceLoader::get_singleton();
	healthbarRef = loader->load("res://UI/Healthbar.tscn");
	get_node_or_null("HP")->connect("mouse_entered", this, "_hovered");
	get_node_or_null("HP")->connect("mouse_exited", this, "_left");
	ScaleStats(1.0f + levelManager->waveCounter / 20.0f);
	health = maxHealth;
}

void godot::Enemy::OnMouseHovered()
{
	healthbar = cast_to<Healthbar>(cast_to<Label>(healthbarRef->instance()));
	healthbar->SetMaxHealth(maxHealth);
	AttachObserver(healthbar);

	Notify(ENEMY_DAMAGED, health);
	get_node("/root/main")->add_child(healthbar);
}

void godot::Enemy::OnMouseLeft()
{
	DetachObserver(healthbar);
	healthbar->queue_free();
	healthbar = nullptr;
}

void godot::Enemy::ScaleStats(float value)
{
	maxHealth *= value;
	speed *= 0.5 + value/4.0f;
}

void godot::Enemy::TakeDamage(int damage)
{
	health -= damage;
	if (healthbar)
	{
		Notify(ENEMY_DAMAGED, health);
	}
	if (health <= 0)
	{
		if (healthbar)
		{
			healthbar->queue_free();
			healthbar = nullptr;
		}

		levelManager->MobDefeated(this->damage);
		queue_free();
	}
}

void Enemy::_physics_process(float delta)
{
	set_offset(get_offset() + speed * delta);

	if (healthbar)
	{
		healthbar->set_position(get_global_mouse_position() + Vector2(40, 0));
	}
	if (get_unit_offset() >= 1)
	{
		levelManager->MobGotThrough(damage);
			queue_free();
	}
}
