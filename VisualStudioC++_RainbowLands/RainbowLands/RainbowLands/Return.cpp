#include "Return.h"

namespace godot
{
	void Return::_register_methods()
	{
		register_method("_init", &Return::_init);
		register_method("_ready", &Return::_ready);
		register_method("_on_button_pressed", &Return::OnButtonPressed);
	}
	void Return::_init()
	{

	}
	void Return::_ready()
	{
		global = Global::get_singleton();
		connect("pressed", this, "_on_button_pressed");
		_resource_loader = ResourceLoader::get_singleton();
	}
	void Return::OnButtonPressed()
	{
		global->SaveSettings();
		get_tree()->change_scene("res://MainMenu/MainMenu.tscn");
	}
}

