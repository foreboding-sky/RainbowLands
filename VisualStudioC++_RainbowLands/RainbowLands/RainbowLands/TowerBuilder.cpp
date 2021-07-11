#include "TowerBuilder.h"

using namespace godot;

TowerBuilder::TowerBuilder()
{
	loader = ResourceLoader::get_singleton();
	towerPrefab = loader->load("res://TD/Towers/TestTower.tscn");
	tower = Object::cast_to<Area2D>(towerPrefab->instance());
}

godot::TowerBuilder::~TowerBuilder()
{
	tower = nullptr;
	loader = nullptr;

	delete tower;
	delete loader;
}

// Get tower instance
Area2D* godot::TowerBuilder::Build()
{
	return tower;
}

// Reset tower instance to default (create a new instance of an Tower object)
void godot::TowerBuilder::Reset()
{
	tower = Object::cast_to<Area2D>(towerPrefab->instance());
}

// Gun sprites
void godot::TowerBuilder::SetGunSprite01()
{
	Object::cast_to<Tower>(tower)->SetGunPath("res://assets/!TOWER DEFENSE OPTIONS!/Towers/TD4_0029_Package-----------------.png");
}

void godot::TowerBuilder::SetGunSprite02()
{
	Object::cast_to<Tower>(tower)->SetGunPath("res://assets/MassiveMilitary/Images/tower_1_0002_Package-----------------.png");
}

// Base platform sprites
void godot::TowerBuilder::SetPlatformSprite01()
{
	Object::cast_to<Tower>(tower)->SetBasePath("res://assets/!TOWER DEFENSE OPTIONS!/Towers/TD4_0037_Package-----------------.png");
}

void godot::TowerBuilder::SetPlatformSprite02()
{
	Object::cast_to<Tower>(tower)->SetBasePath("res://assets/MassiveMilitary/Images/tower_1_0002_Package-----------------.png");
}

// Attack speed
void godot::TowerBuilder::SetAttackSpeedLow()
{
	Object::cast_to<Tower>(tower)->SetAttackSpeed(1);
}

void godot::TowerBuilder::SetAttackSpeedHigh()
{
	Object::cast_to<Tower>(tower)->SetAttackSpeed(0.5);
}

// Projectiles
void godot::TowerBuilder::SetAmmoTypeProjectile01()
{
	Ref<PackedScene> projectilePrefab = loader->load("res://TD/Projectiles/Projectile_1.tscn");
	Object::cast_to<Tower>(tower)->SetProjectilePrefab(projectilePrefab);
}

void godot::TowerBuilder::SetAmmoTypeProjectile02()
{
	Ref<PackedScene> projectilePrefab = loader->load("res://TD/Projectiles/Projectile_1.tscn");
	Object::cast_to<Tower>(tower)->SetProjectilePrefab(projectilePrefab);
}

// Projectiles
void godot::TowerBuilder::SetTowerPlacementCost30()
{
	Object::cast_to<Tower>(tower)->SetTowerCost(30);
}
// Targeting methods
void godot::TowerBuilder::SetTargetingClosestNoLock()
{
	ClosestNoLock* method = new ClosestNoLock();
	Object::cast_to<Tower>(tower)->SetTargetingMethod(method);
}