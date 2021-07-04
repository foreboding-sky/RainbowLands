#include "SpawnTower.h"

namespace godot
{
	void SpawnTower::_register_methods()
	{
		register_method("_init", &SpawnTower::_init);
		register_method("_ready", &SpawnTower::_ready);
		register_method("_on_button_pressed", &SpawnTower::_on_button_pressed);
	}
	void SpawnTower::_init()
	{

	}
	void SpawnTower::_ready()
	{
		_loader = ResourceLoader::get_singleton();

		connect("pressed", this, "_on_button_pressed");
	}
	void SpawnTower::_on_button_pressed()
	{
		Ref<PackedScene> prefab = _loader->load("res://TD/Towers/TestTower.tscn");
		Area2D* tower = cast_to<Area2D>(prefab->instance());
		get_node("/root/main/entities")->add_child(tower);
	}
}

