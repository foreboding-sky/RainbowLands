#include "SpawnTower1.h"

namespace godot
{
	void SpawnTower1::_register_methods()
	{
		register_method("_init", &SpawnTower1::_init);
		register_method("_ready", &SpawnTower1::_ready);
		register_method("_on_button_pressed", &SpawnTower1::OnButtonPressed);
		register_method("_on_mouse_hovered", &SpawnTower1::OnMouseHovered);
		register_method("_on_mouse_left", &SpawnTower1::OnMouseLeft);
		register_method("BuildTower", &SpawnTower1::BuildTower);
	}
	void SpawnTower1::_init()
	{

	}
	void SpawnTower1::_ready()
	{

		loader = ResourceLoader::get_singleton();
		levelManager = LevelManager::get_singleton();
		texture = this->get_button_icon();
		iconSize = texture.ptr()->get_size();
		
		//size = Vector2((iconSize.x/(iconSize.x/)))
		set_size(Vector2(300,200));
		connect("pressed", this, "_on_button_pressed");
		connect("mouse_entered", this, "_on_mouse_hovered");
		connect("mouse_exited", this, "_on_mouse_left");
	}
	void SpawnTower1::OnButtonPressed()
	{
		BuildTower();
		get_child(0)->set("visible", false);
		get_parent()->get_parent()->get_parent()->set("visible", false);
	}
	void SpawnTower1::OnMouseHovered()
	{
		get_child(0)->set("visible", true);
	}
	void SpawnTower1::OnMouseLeft()
	{
		get_child(0)->set("visible", false);
	}
	void SpawnTower1::BuildTower()
	{
		TowerBuilder builder;
		builder.SetAmmoTypeProjectile01();
		builder.SetAttackSpeedHigh();
		builder.SetGunSprite02();
		builder.SetPlatformSprite02();
		builder.SetTowerPlacementCost30();
		builder.SetTargetingClosestNoLock();
		builder.SetShootingRangeNormal();
		Area2D* tower = builder.Build();


		if(levelManager->currency >= cast_to<Tower>(tower)->GetTowerPlacementCost())
			get_node("/root/main/entities")->add_child(tower);
		builder.Reset();

	}
}

