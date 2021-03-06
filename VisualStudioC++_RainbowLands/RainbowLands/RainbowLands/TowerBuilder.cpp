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
	Object::cast_to<Tower>(tower)->SetGunPath("res://TD/Towers/TowerSprites/Tower5/Turret5.png");
}

void godot::TowerBuilder::SetGunSprite02()
{
	Object::cast_to<Tower>(tower)->SetGunPath("res://TD/Towers/TowerSprites/Tower2/Turret2.png");
}

void godot::TowerBuilder::SetGunSprite03()
{
	Object::cast_to<Tower>(tower)->SetGunPath("res://TD/Towers/TowerSprites/Tower3/Turret3.png");
}

void godot::TowerBuilder::SetGunSprite04()
{
	Object::cast_to<Tower>(tower)->SetGunPath("res://TD/Towers/TowerSprites/Tower7/Turret7.png");
}

void godot::TowerBuilder::SetGunSprite05()
{
	Object::cast_to<Tower>(tower)->SetGunPath("res://TD/Towers/TowerSprites/Tower6/Turret6.png");
}



// Base platform sprites
void godot::TowerBuilder::SetPlatformSprite01()
{
	Object::cast_to<Tower>(tower)->SetBasePath("res://TD/Towers/TowerSprites/Tower5/Base5.png");
}

void godot::TowerBuilder::SetPlatformSprite02()
{
	Object::cast_to<Tower>(tower)->SetBasePath("res://TD/Towers/TowerSprites/Tower2/Base2.png");
}

void godot::TowerBuilder::SetPlatformSprite03()
{
	Object::cast_to<Tower>(tower)->SetBasePath("res://TD/Towers/TowerSprites/Tower3/Base3.png");
}

void godot::TowerBuilder::SetPlatformSprite04()
{
	Object::cast_to<Tower>(tower)->SetBasePath("res://TD/Towers/TowerSprites/Tower7/Base7.png");
}

void godot::TowerBuilder::SetPlatformSprite05()
{
	Object::cast_to<Tower>(tower)->SetBasePath("res://TD/Towers/TowerSprites/Tower6/Base6.png");
}



// Attack speed
void godot::TowerBuilder::SetAttackSpeedVeryLow()
{
	Object::cast_to<Tower>(tower)->SetAttackSpeed(3);
}

void godot::TowerBuilder::SetAttackSpeedLow()
{
	Object::cast_to<Tower>(tower)->SetAttackSpeed(2);
}

void godot::TowerBuilder::SetAttackSpeedNormal()
{
	Object::cast_to<Tower>(tower)->SetAttackSpeed(1);
}

void godot::TowerBuilder::SetAttackSpeedHigh()
{
	Object::cast_to<Tower>(tower)->SetAttackSpeed(0.4);
}

void godot::TowerBuilder::SetAttackSpeedVeryHigh()
{
	Object::cast_to<Tower>(tower)->SetAttackSpeed(0.15);
}



// Projectiles
void godot::TowerBuilder::SetAmmoTypeProjectile01()
{
	Ref<PackedScene> projectilePrefab = loader->load("res://TD/Projectiles/Projectile_1.tscn");
	Object::cast_to<Tower>(tower)->SetProjectilePrefab(projectilePrefab);
}

void godot::TowerBuilder::SetAmmoTypeProjectile02()
{
	Ref<PackedScene> projectilePrefab = loader->load("res://TD/Projectiles/LunarProjectile.tscn");
	Object::cast_to<Tower>(tower)->SetProjectilePrefab(projectilePrefab);
}

void godot::TowerBuilder::SetAmmoTypeProjectile03()
{
	Ref<PackedScene> projectilePrefab = loader->load("res://TD/Projectiles/MinigunProjectile.tscn");
	Object::cast_to<Tower>(tower)->SetProjectilePrefab(projectilePrefab);
}

void godot::TowerBuilder::SetAmmoTypeProjectile04()
{
	Ref<PackedScene> projectilePrefab = loader->load("res://TD/Projectiles/SniperProjetile.tscn");
	Object::cast_to<Tower>(tower)->SetProjectilePrefab(projectilePrefab);
}

void godot::TowerBuilder::SetAmmoTypeProjectile05()
{
	Ref<PackedScene> projectilePrefab = loader->load("res://TD/Projectiles/SawAOE.tscn");
	Object::cast_to<Tower>(tower)->SetProjectilePrefab(projectilePrefab);
}



// Aggro range
void godot::TowerBuilder::SetShootingRangeShort()
{
	Ref<CircleShape2D> shape = CircleShape2D::_new();
	shape.ptr()->set_radius(180);
	Object::cast_to<Tower>(tower)->SetCollisionShape(shape);
}

void godot::TowerBuilder::SetShootingRangeNormal()
{
	Ref<CircleShape2D> shape = CircleShape2D::_new();
	shape.ptr()->set_radius(250);
	Object::cast_to<Tower>(tower)->SetCollisionShape(shape);
}

void godot::TowerBuilder::SetShootingRangeLong()
{
	Ref<CircleShape2D> shape = CircleShape2D::_new();
	shape.ptr()->set_radius(350);
	Object::cast_to<Tower>(tower)->SetCollisionShape(shape);
}

void godot::TowerBuilder::SetShootingRangeVeryLong()
{
	Ref<CircleShape2D> shape = CircleShape2D::_new();
	shape.ptr()->set_radius(500);
	Object::cast_to<Tower>(tower)->SetCollisionShape(shape);
}



// Projectiles
void godot::TowerBuilder::SetTowerPlacementCost30()
{
	Object::cast_to<Tower>(tower)->SetTowerCost(20);
}

void godot::TowerBuilder::SetTowerPlacementCost50()
{
	Object::cast_to<Tower>(tower)->SetTowerCost(50);
}

void godot::TowerBuilder::SetTowerPlacementCost70()
{
	Object::cast_to<Tower>(tower)->SetTowerCost(100);
}

void godot::TowerBuilder::SetTowerPlacementCost120()
{
	Object::cast_to<Tower>(tower)->SetTowerCost(150);
}

void godot::TowerBuilder::SetTowerPlacementCost200()
{
	Object::cast_to<Tower>(tower)->SetTowerCost(250);
}



// Targeting methods
void godot::TowerBuilder::SetTargetingClosestNoLock()
{
	ClosestNoLock* method = new ClosestNoLock();
	Object::cast_to<Tower>(tower)->SetTargetingMethod(method);
}