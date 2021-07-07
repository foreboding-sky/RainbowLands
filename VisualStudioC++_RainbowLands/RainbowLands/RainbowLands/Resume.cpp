#include "Resume.h"

namespace godot
{
	void Resume::_register_methods()
	{
		register_method("_init", &Resume::_init);
		register_method("_ready", &Resume::_ready);
		register_method("_on_button_pressed", &Resume::_on_button_pressed);
	}
	void Resume::_init()
	{

	}
	void Resume::_ready()
	{
		connect("pressed", this, "_on_button_pressed");
	}
	void Resume::_on_button_pressed()
	{
		_is_paused = !get_tree()->is_paused();
		get_tree()->set_pause(_is_paused);
		get_parent()->get_parent()->set("visible", _is_paused);

	}
}

