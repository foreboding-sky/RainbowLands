#include "Resume.h"

namespace godot
{
	void Resume::_register_methods()
	{
		register_method("_init", &Resume::_init);
		register_method("_ready", &Resume::_ready);
		register_method("_on_button_pressed", &Resume::OnButtonPressed);
	}
	void Resume::_init()
	{

	}
	void Resume::_ready()
	{
		connect("pressed", this, "_on_button_pressed");
	}
	void Resume::OnButtonPressed()
	{
		isPaused = !get_tree()->is_paused();
		get_tree()->set_pause(isPaused);
		get_parent()->get_parent()->set("visible", isPaused);

	}
}

