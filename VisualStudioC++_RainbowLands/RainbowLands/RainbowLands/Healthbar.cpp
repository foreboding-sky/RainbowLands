#include "Healthbar.h"

using namespace godot;
Healthbar::Healthbar() {}

Healthbar::~Healthbar() {}

void Healthbar::_register_methods()
{
	register_method((char*)"_init", &Healthbar::_init);
	register_method((char*)"_ready", &Healthbar::_ready);
	register_method((char*)"SetMaxHealth", &Healthbar::SetMaxHealth);

}

void Healthbar::Update(Message& msg, int& param)
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

void Healthbar::_init() {}

void Healthbar::_ready() 
{

}

void Healthbar::UpdateHealth(int health)
{
	std::string converter = std::to_string(health) + "|" + std::to_string(maxHealth);
	String text = String(converter.c_str());
	set_text(text);
}

void Healthbar::SetMaxHealth(int value)
{
	maxHealth = value;
}



