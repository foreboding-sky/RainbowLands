#include "StartWave.h"

namespace godot
{
	void StartWave::_register_methods()
	{
		register_method("_init", &StartWave::_init);
		register_method("_ready", &StartWave::_ready);
		register_method("_on_button_pressed", &StartWave::_on_button_pressed);
	}
	void StartWave::_init()
	{

	}
	void StartWave::_ready()
	{
		Godot::print("b3");
		levelManager->get_singleton();
		connect("pressed", this, "_on_button_pressed");
		Godot::print("b4");
	}
	void StartWave::_on_button_pressed()
	{
		Godot::print("b1");
		//levelManager->StartWave();
		Godot::print("b2");
	}
}

