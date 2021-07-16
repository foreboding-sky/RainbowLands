#include "SpawnTower2.h"

namespace godot
{
	void SpawnTower2::_register_methods()
	{
		register_method("_init", &SpawnTower2::_init);
		register_method("_ready", &SpawnTower2::_ready);
		register_method("_on_button_pressed", &SpawnTower2::OnButtonPressed);
		register_method("_on_mouse_hovered", &SpawnTower2::OnMouseHovered);
		register_method("_on_mouse_left", &SpawnTower2::OnMouseLeft);
		register_method("BuildTower", &SpawnTower2::BuildTower);
	}
	void SpawnTower2::_init()
	{

	}
	void SpawnTower2::_ready()
	{

		loader = ResourceLoader::get_singleton();
		levelManager = LevelManager::get_singleton();
		texture = this->get_button_icon();
		iconSize = texture.ptr()->get_size();

		set_size(Vector2(300, 200));
		connect("pressed", this, "_on_button_pressed");
		connect("mouse_entered", this, "_on_mouse_hovered");
		connect("mouse_exited", this, "_on_mouse_left");
	}
	void SpawnTower2::OnButtonPressed()
	{
		BuildTower();
		get_child(0)->set("visible", false);
		get_parent()->get_parent()->get_parent()->set("visible", false);
	}
	void SpawnTower2::OnMouseHovered()
	{
		get_child(0)->set("visible", true);
	}
	void SpawnTower2::OnMouseLeft()
	{
		get_child(0)->set("visible", false);
	}
	void SpawnTower2::BuildTower()
	{
		TowerBuilder builder;
		builder.SetAmmoTypeProjectile02();
		builder.SetAttackSpeedNormal();
		builder.SetGunSprite03();
		builder.SetPlatformSprite03();
		builder.SetTowerPlacementCost50();
		builder.SetTargetingClosestNoLock();
		builder.SetShootingRangeNormal();
		Area2D* tower = builder.Build();

		if (levelManager->currency >= cast_to<Tower>(tower)->GetTowerPlacementCost())
			get_node("/root/main/entities")->add_child(tower);

		builder.Reset();
	}
}

