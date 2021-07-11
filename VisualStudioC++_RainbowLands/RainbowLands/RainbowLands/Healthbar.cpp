#include "Healthbar.h"

using namespace godot;
Healthbar::Healthbar() {}

Healthbar::~Healthbar() {}

void Healthbar::_register_methods()
{
	register_method((char*)"_init", &Healthbar::_init);
	register_method((char*)"_ready", &Healthbar::_ready);
	register_method((char*)"SetValue", &Healthbar::SetValue);
}

void Healthbar::SetValue(float value)
{
	set_value(value);
}

void Healthbar::_init() {}

void Healthbar::_ready() {}

