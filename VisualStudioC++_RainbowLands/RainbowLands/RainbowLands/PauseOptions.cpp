#include "PauseOptions.h"

namespace godot
{
	void PauseOptions::_register_methods()
	{
		register_method("_init", &PauseOptions::_init);
		register_method("_ready", &PauseOptions::_ready);
		register_method("_on_button_pressed", &PauseOptions::OnButtonPressed);
	}
	void PauseOptions::_init()
	{

	}
	void PauseOptions::_ready()
	{
		connect("pressed", this, "_on_button_pressed");

	}
	void PauseOptions::OnButtonPressed()
	{

		get_child(0)->get_child(0)->set("visible", true);
	}
}

