#include "Arrow.h"

using namespace godot;
Arrow::Arrow()
{
	_speed = 100;
}

Arrow::~Arrow()
{
}

void Arrow::_register_methods()
{
	register_method((char*)"_physics_process", &Arrow::_physics_process);
	register_method((char*)"_init", &Arrow::_init);
	register_method((char*)"_ready", &Arrow::_ready);
	register_property<Arrow, int>("Speed", &Arrow::_speed, 100);
}

void Arrow::_init() {}

void Arrow::_ready() {}

void Arrow::_physics_process(float delta)
{
	set_offset(get_offset() + _speed * delta);
}
