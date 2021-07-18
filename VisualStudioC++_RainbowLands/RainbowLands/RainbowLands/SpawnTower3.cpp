#include "SpawnTower3.h"

namespace godot
{
	void SpawnTower3::_register_methods()
	{
		register_method("_init", &SpawnTower3::_init);
		register_method("_ready", &SpawnTower3::_ready);
		register_method("_on_button_pressed", &SpawnTower3::OnButtonPressed);
		register_method("_on_mouse_hovered", &SpawnTower3::OnMouseHovered);
		register_method("_on_mouse_left", &SpawnTower3::OnMouseLeft);
		register_method("BuildTower", &SpawnTower3::BuildTower);
	}
	void SpawnTower3::_init()
	{

	}
	void SpawnTower3::_ready()
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
	void SpawnTower3::OnButtonPressed()
	{
		BuildTower();
		get_child(0)->set("visible", false);
		get_parent()->get_parent()->get_parent()->set("visible", false);
	}
	void SpawnTower3::OnMouseHovered()
	{
		get_child(0)->set("visible", true);
	}
	void SpawnTower3::OnMouseLeft()
	{
		get_child(0)->set("visible", false);
	}
	void SpawnTower3::BuildTower()
	{
		TowerBuilder builder;
		builder.SetAmmoTypeProjectile03();
		builder.SetAttackSpeedVeryHigh();
		builder.SetGunSprite01();
		builder.SetPlatformSprite01();
		builder.SetTowerPlacementCost70();
		builder.SetTargetingClosestNoLock();
		builder.SetShootingRangeShort();
		Area2D* tower = builder.Build();

		if (levelManager->currency >= cast_to<Tower>(tower)->GetTowerPlacementCost())
			get_node("/root/main/entities")->add_child(tower);

		builder.Reset();
	}
}

