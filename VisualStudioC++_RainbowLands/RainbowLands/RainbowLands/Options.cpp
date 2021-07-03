#include "Options.h"

namespace godot
{
	void Options::_register_methods()
	{
		register_method("_init", &Options::_init);
		register_method("_ready", &Options::_ready);
		register_method("_on_button_pressed", &Options::_on_button_pressed);
	}
	void Options::_init()
	{

	}
	void Options::_ready()
	{
		connect("pressed", this, "_on_button_pressed");
		_resource_loader = ResourceLoader::get_singleton();
	}
	void Options::_on_button_pressed()
	{
		get_tree()->change_scene("res://MainMenu/Options/Options.tscn");
	}
}

