#include "PauseMenu.h"

namespace godot
{
	void PauseMenu::_register_methods()
	{
		register_method("_init", &PauseMenu::_init);
		register_method("_ready", &PauseMenu::_ready);
		register_method("_input", &PauseMenu::_input);
	}
	void PauseMenu::_init()
	{

	}
	void PauseMenu::_ready()
	{

	}
	void PauseMenu::_input(InputEvent* event)
	{
		if (event->is_action_pressed("pause"))
		{
			isPaused = !get_tree()->is_paused();
			get_tree()->set_pause(isPaused);
			set_visible(isPaused);
		}

	}
	
}

