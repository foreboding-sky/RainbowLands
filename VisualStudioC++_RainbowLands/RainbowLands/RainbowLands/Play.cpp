#include "Play.h"

namespace godot
{
	void Play::_register_methods()
	{
		register_method("_init", &Play::_init);
		register_method("_ready", &Play::_ready);
		register_method("on_button_pressed", &Play::on_button_pressed);
	}
	void Play::_init()
	{

	}
	void Play::_ready()
	{
		connect("pressed", this, "on_button_pressed");
		_resource_loader = ResourceLoader::get_singleton();
	}
	void Play::on_button_pressed()
	{
		Ref<PackedScene> level = _resource_loader->load("res:://TD//Test.tscn");
		get_node("/root")->add_child(level->instance());
	}
}

