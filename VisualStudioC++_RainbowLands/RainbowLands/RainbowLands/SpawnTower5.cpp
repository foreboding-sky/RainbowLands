#include "SpawnTower5.h"

namespace godot
{
	void SpawnTower5::_register_methods()
	{
		register_method("_init", &SpawnTower5::_init);
		register_method("_ready", &SpawnTower5::_ready);
		register_method("_on_button_pressed", &SpawnTower5::OnButtonPressed);
		register_method("_on_mouse_hovered", &SpawnTower5::OnMouseHovered);
		register_method("_on_mouse_left", &SpawnTower5::OnMouseLeft);
		register_method("BuildTower", &SpawnTower5::BuildTower);
	}
	void SpawnTower5::_init()
	{

	}
	void SpawnTower5::_ready()
	{

		loader = ResourceLoader::get_singleton();
		levelManager = LevelManager::get_singleton();
		texture = this->get_button_icon();
		iconSize = texture.ptr()->get_size();

		//size = Vector2((iconSize.x/(iconSize.x/)))
		set_size(Vector2(300, 200));
		connect("pressed", this, "_on_button_pressed");
		connect("mouse_entered", this, "_on_mouse_hovered");
		connect("mouse_exited", this, "_on_mouse_left");
	}
	void SpawnTower5::OnButtonPressed()
	{
		BuildTower();
		get_parent()->get_parent()->get_parent()->set("visible", false);
	}
	void SpawnTower5::OnMouseHovered()
	{
		Godot::print("visivle");
		get_child(0)->set("visible", true);
	}
	void SpawnTower5::OnMouseLeft()
	{
		Godot::print("unvisivle");
		//set_visible(false);
		get_child(0)->set("visible", false);
	}
	void SpawnTower5::BuildTower()
	{
		TowerBuilder builder;
		builder.SetAmmoTypeProjectile05();
		builder.SetAttackSpeedLow();
		builder.SetGunSprite05();
		builder.SetPlatformSprite05();
		builder.SetTowerPlacementCost200();
		builder.SetTargetingClosestNoLock();
		builder.SetShootingRangeShort();
		Area2D* tower = builder.Build();

		if (levelManager->currency >= cast_to<Tower>(tower)->GetTowerPlacementCost())
			get_node("/root/main/entities")->add_child(tower);

		builder.Reset();
	}
}

