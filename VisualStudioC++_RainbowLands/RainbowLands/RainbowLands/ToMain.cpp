#include "ToMain.h"

namespace godot
{
	void ToMain::_register_methods()
	{
		register_method("_init", &ToMain::_init);
		register_method("_ready", &ToMain::_ready);
		register_method("_on_button_pressed", &ToMain::_on_button_pressed);
	}
	void ToMain::_init()
	{

	}
	void ToMain::_ready()
	{
		connect("pressed", this, "_on_button_pressed");
	}
	void ToMain::_on_button_pressed()
	{
		get_tree()->change_scene("res://MainMenu/MainMenu.tscn");
	}
}

