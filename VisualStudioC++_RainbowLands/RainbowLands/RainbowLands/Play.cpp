#include "Play.h"

namespace godot
{
	void Play::_register_methods()
	{
		register_method("_init", &Play::_init);
		register_method("_ready", &Play::_ready);
		register_method("_on_button_pressed", &Play::_on_button_pressed);
	}
	void Play::_init()
	{

	}
	void Play::_ready()
	{
		connect("pressed", this, "_on_button_pressed");
		_resource_loader = ResourceLoader::get_singleton();
	}
	void Play::_on_button_pressed()
	{
		get_tree()->change_scene("res://TD//Test.tscn");
	}
}

