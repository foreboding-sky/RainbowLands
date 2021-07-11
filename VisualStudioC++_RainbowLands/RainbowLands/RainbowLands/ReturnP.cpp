#include "ReturnP.h"

namespace godot
{
	void ReturnP::_register_methods()
	{
		register_method("_init", &ReturnP::_init);
		register_method("_ready", &ReturnP::_ready);
		register_method("_on_button_pressed", &ReturnP::OnButtonPressed);
	}
	void ReturnP::_init()
	{

	}
	void ReturnP::_ready()
	{
		connect("pressed", this, "_on_button_pressed");

	}
	void ReturnP::OnButtonPressed()
	{
		get_parent()->get_parent()->set("visible", false);
	}
}

