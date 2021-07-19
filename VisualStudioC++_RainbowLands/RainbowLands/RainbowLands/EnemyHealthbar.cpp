#include "EnemyHealthbar.h"

using namespace godot;
EnemyHealthbar::EnemyHealthbar() {}

EnemyHealthbar::~EnemyHealthbar() {}

void EnemyHealthbar::_register_methods()
{
	register_method((char*)"_init", &EnemyHealthbar::_init);
	register_method((char*)"_ready", &EnemyHealthbar::_ready);
	register_method((char*)"SetMaxHealth", &EnemyHealthbar::SetMaxHealth);

}

void EnemyHealthbar::Update(Message& msg, int& param)
{
	switch (msg)
	{
		case ENEMY_DAMAGED:
		{
			UpdateHealth(param);
			break;
		}

	}
}

void EnemyHealthbar::_init() {}

void EnemyHealthbar::_ready() 
{

}

void EnemyHealthbar::UpdateHealth(int health)
{
	std::string converter = std::to_string(health) + "|" + std::to_string(maxHealth);
	String text = String(converter.c_str());
	set_text(text);
}

void EnemyHealthbar::SetMaxHealth(int value)
{
	maxHealth = value;
}



