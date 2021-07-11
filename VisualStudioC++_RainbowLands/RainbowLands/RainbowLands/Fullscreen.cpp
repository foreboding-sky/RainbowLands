#include "Fullscreen.h"

namespace godot
{
	void Fullscreen::_register_methods()
	{
		register_method("_init", &Fullscreen::_init);
		register_method("_ready", &Fullscreen::_ready);
		register_method("_on_button_pressed", &Fullscreen::OnButtonPressed);
	}
	void Fullscreen::_init()
	{

	}
	void Fullscreen::_ready()
	{
		global = Global::get_singleton();
		set_pressed(global->GetFullscreen());
		connect("toggled", this, "_on_button_pressed");

	}
	void Fullscreen::OnButtonPressed()
	{
		global->SetFullscreen(this->is_pressed());
	}
}

