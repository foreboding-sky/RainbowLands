#include "Load.h"

namespace godot
{
	void Load::_register_methods()
	{
		register_method("_init", &Load::_init);
		register_method("_ready", &Load::_ready);
		register_method("_on_button_pressed", &Load::_on_button_pressed);
	}
	void Load::_init()
	{

	}
	void Load::_ready()
	{
		connect("pressed", this, "_on_button_pressed");
	}
	void Load::_on_button_pressed()
	{
		_is_paused = !get_tree()->is_paused();
		get_tree()->set_pause(_is_paused);
		get_parent()->get_parent()->set("visible", _is_paused);

	}
}

