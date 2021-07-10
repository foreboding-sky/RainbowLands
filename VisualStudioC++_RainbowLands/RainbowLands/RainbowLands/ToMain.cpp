#include "ToMain.h"

namespace godot
{
	void ToMain::_register_methods()
	{
		register_method("_init", &ToMain::_init);
		register_method("_ready", &ToMain::_ready);
		register_method("_on_button_pressed", &ToMain::OnButtonPressed);
	}
	void ToMain::_init()
	{

	}
	void ToMain::_ready()
	{
		connect("pressed", this, "_on_button_pressed");
	}
	void ToMain::OnButtonPressed()
	{
		get_tree()->set_pause(false);
		get_tree()->change_scene("res://MainMenu/MainMenu.tscn");
	}
}

