#include "TowerBuilder.h"

using namespace godot;

TowerBuilder::TowerBuilder()
{
	_loader = ResourceLoader::get_singleton();
	_towerPrefab = _loader->load("res://TD/Towers/TestTower.tscn");
	_tower = Object::cast_to<Area2D>(_towerPrefab->instance());
}

godot::TowerBuilder::~TowerBuilder()
{
	_tower = nullptr;
	_loader = nullptr;

	delete _tower;
	delete _loader;
}

// Get tower instance
Area2D* godot::TowerBuilder::Build()
{
	return _tower;
}

// Reset tower instance to default (create a new instance of an Tower object)
void godot::TowerBuilder::Reset()
{
	_tower = Object::cast_to<Area2D>(_towerPrefab->instance());
}

// Gun sprites
void godot::TowerBuilder::SetGunSprite01()
{
	_tower->call("_set_gun_path", "res://assets/MassiveMilitary/Images/Turret_2_0004_Bitmap------------------.png");
}

void godot::TowerBuilder::SetGunSprite02()
{
	_tower->call("_set_gun_path", "res://assets/MassiveMilitary/Images/Turret_2_0004_Bitmap------------------.png");
}

// Base platform sprites
void godot::TowerBuilder::SetPlatformSprite01()
{
	_tower->call("_set_base_path", "res://assets/MassiveMilitary/Images/tower_1_0002_Package-----------------.png");
}

void godot::TowerBuilder::SetPlatformSprite02()
{
	_tower->call("_set_base_path", "res://assets/MassiveMilitary/Images/tower_1_0002_Package-----------------.png");
}

// Attack speed
void godot::TowerBuilder::SetAttackSpeedLow()
{
	_tower->call("_set_attack_speed", 1.0);
}

void godot::TowerBuilder::SetAttackSpeedHigh()
{
	_tower->call("_set_attack_speed", 0.5);
}

// Projectiles
void godot::TowerBuilder::SetAmmoTypeProjectile01()
{
	Ref<PackedScene> _projectile_prefab = _loader->load("res://TD/Projectiles/Projectile_1.tscn");
	_tower->call("_set_projectile_prefab", _projectile_prefab);
}

void godot::TowerBuilder::SetAmmoTypeProjectile02()
{
	Ref<PackedScene> _projectile_prefab = _loader->load("res://TD/Projectiles/Projectile_1.tscn");
	_tower->call("_set_projectile_prefab", _projectile_prefab);
}