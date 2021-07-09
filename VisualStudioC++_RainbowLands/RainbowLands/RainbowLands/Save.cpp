#include "Save.h"

namespace godot
{
	void Save::_register_methods()
	{
		register_method("_init", &Save::_init);
		register_method("_ready", &Save::_ready);
		register_method("_on_button_pressed", &Save::_on_button_pressed);
	}
	void Save::_init()
	{

	}
	void Save::_ready()
	{
		connect("pressed", this, "_on_button_pressed");
	}
	void Save::_on_button_pressed()
	{
		_is_paused = !get_tree()->is_paused();
		get_tree()->set_pause(_is_paused);
		get_parent()->get_parent()->set("visible", _is_paused);

	}
	void Save::_save()
	{
		File save;
		save.open("user://savegame.save", File::WRITE);
		auto save_nodes = get_tree()->get_nodes_in_group("Saveable");
		
		for (int i = 0; i < save_nodes.size(); i++)
		{
			if (cast_to<Node>(save_nodes[i])->get_filename().empty());
			{
				Godot::print("Node is not an instanced scene");
				
			}
		}
	}
}

