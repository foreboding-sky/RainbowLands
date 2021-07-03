#include "PauseManager.h"

namespace godot
{
	void PauseManager::_register_methods()
	{
		register_method("_init", &PauseManager::_init);
		register_method("_ready", &PauseManager::_ready);
		register_method("_process", &PauseManager::_process);
	}
	void PauseManager::_init()
	{

	}
	void PauseManager::_ready()
	{
		_input = Input::get_singleton();
		_resource_loader = ResourceLoader::get_singleton();
		pause_menu = _resource_loader->load("res://PauseMenu/PauseMenu.tscn");
	}
	void PauseManager::_process(float delta)
	{
		if (_input->is_action_pressed("KEY_ESCAPE"))
		{
			if (!get_tree()->is_paused())
			{
				get_tree()->set_pause(true);

			}
			else
			{
				get_tree()->set_pause(false);

			}
		}
	}
}

