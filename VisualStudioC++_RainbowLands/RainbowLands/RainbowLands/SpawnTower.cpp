#include "SpawnTower.h"

namespace godot
{
	void SpawnTower::_register_methods()
	{
		register_method("_init", &SpawnTower::_init);
		register_method("_ready", &SpawnTower::_ready);
		register_method("_on_button_pressed", &SpawnTower::_on_button_pressed);
		register_method("_on_mouse_hovered", &SpawnTower::_on_mouse_hovered);
		register_method("_on_mouse_left", &SpawnTower::_on_mouse_left);
	}
	void SpawnTower::_init()
	{

	}
	void SpawnTower::_ready()
	{
		_loader = ResourceLoader::get_singleton();
		_texture = this->get_button_icon();
		_icon_size = _texture.ptr()->get_size();
		
		//_size = Vector2((_icon_size.x/(_icon_size.x/)))
		set_size(Vector2(300,200));
		connect("pressed", this, "_on_button_pressed");
		connect("mouse_entered", this, "_on_mouse_hovered");
		connect("mouse_exited", this, "_on_mouse_left");
	}
	void SpawnTower::_on_button_pressed()
	{
		Ref<PackedScene> prefab = _loader->load("res://TD/Towers/TestTower.tscn");		
		Area2D* tower = cast_to<Area2D>(prefab->instance());
		get_node("/root/main/entities")->add_child(tower);
	}
	void SpawnTower::_on_mouse_hovered()
	{
		Godot::print("visivle");
		get_child(0)->set("visible", true);
	}
	void SpawnTower::_on_mouse_left()
	{
		Godot::print("unvisivle");
		//set_visible(false);
		get_child(0)->set("visible", false);
	}
}

