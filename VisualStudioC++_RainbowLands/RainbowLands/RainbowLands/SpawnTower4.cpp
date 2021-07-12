#include "SpawnTower4.h"

namespace godot
{
	void SpawnTower4::_register_methods()
	{
		register_method("_init", &SpawnTower4::_init);
		register_method("_ready", &SpawnTower4::_ready);
		register_method("_on_button_pressed", &SpawnTower4::OnButtonPressed);
		register_method("_on_mouse_hovered", &SpawnTower4::OnMouseHovered);
		register_method("_on_mouse_left", &SpawnTower4::OnMouseLeft);
		register_method("BuildTower", &SpawnTower4::BuildTower);
	}
	void SpawnTower4::_init()
	{

	}
	void SpawnTower4::_ready()
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
	void SpawnTower4::OnButtonPressed()
	{
		BuildTower();
		get_parent()->get_parent()->get_parent()->set("visible", false);
	}
	void SpawnTower4::OnMouseHovered()
	{
		Godot::print("visivle");
		get_child(0)->set("visible", true);
	}
	void SpawnTower4::OnMouseLeft()
	{
		Godot::print("unvisivle");
		//set_visible(false);
		get_child(0)->set("visible", false);
	}
	void SpawnTower4::BuildTower()
	{
		TowerBuilder builder;
		builder.SetAmmoTypeProjectile04();
		builder.SetAttackSpeedVeryLow();
		builder.SetGunSprite04();
		builder.SetPlatformSprite04();
		builder.SetTowerPlacementCost120();
		builder.SetTargetingClosestNoLock();
		builder.SetShootingRangeVeryLong();
		Area2D* tower = builder.Build();

		if (levelManager->currency >= cast_to<Tower>(tower)->GetTowerPlacementCost())
			get_node("/root/main/entities")->add_child(tower);

		builder.Reset();
	}
}

