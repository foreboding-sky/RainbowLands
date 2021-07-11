#include "SpawnTower.h"

namespace godot
{
	void SpawnTower::_register_methods()
	{
		register_method("_init", &SpawnTower::_init);
		register_method("_ready", &SpawnTower::_ready);
		register_method("_on_button_pressed", &SpawnTower::OnButtonPressed);
		register_method("_on_mouse_hovered", &SpawnTower::OnMouseHovered);
		register_method("_on_mouse_left", &SpawnTower::OnMouseLeft);
		register_method("BuildTower", &SpawnTower::BuildTower);
	}
	void SpawnTower::_init()
	{

	}
	void SpawnTower::_ready()
	{

		loader = ResourceLoader::get_singleton();
		_texture = this->get_button_icon();
		_icon_size = _texture.ptr()->get_size();
		
		//_size = Vector2((_icon_size.x/(_icon_size.x/)))
		set_size(Vector2(300,200));
		connect("pressed", this, "_on_button_pressed");
		connect("mouse_entered", this, "_on_mouse_hovered");
		connect("mouse_exited", this, "_on_mouse_left");
	}
	void SpawnTower::OnButtonPressed()
	{
		BuildTower();
		get_parent()->get_parent()->get_parent()->set("visible", false);
	}
	void SpawnTower::OnMouseHovered()
	{
		Godot::print("visivle");
		get_child(0)->set("visible", true);
	}
	void SpawnTower::OnMouseLeft()
	{
		Godot::print("unvisivle");
		//set_visible(false);
		get_child(0)->set("visible", false);
	}
	void SpawnTower::BuildTower()
	{
		TowerBuilder builder;
		builder.SetAmmoTypeProjectile01();
		builder.SetAttackSpeedHigh();
		builder.SetGunSprite01();
		builder.SetPlatformSprite01();
		builder.SetTowerPlacementCost30();
		get_node("/root/main/entities")->add_child(builder.Build());
		builder.Reset();

	}
}

