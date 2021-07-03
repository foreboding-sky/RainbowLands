#include "Exit.h"

namespace godot
{
	void Exit::_register_methods()
	{
		register_method("_init", &Exit::_init);
		register_method("_ready", &Exit::_ready);
		register_method("_on_button_pressed", &Exit::_on_button_pressed);
	}
	void Exit::_init()
	{

	}
	void Exit::_ready()
	{
		connect("pressed", this, "_on_button_pressed");
	}
	void Exit::_on_button_pressed()
	{
		get_tree()->quit();
	}
}

