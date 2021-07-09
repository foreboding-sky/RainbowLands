#include "TowerBuilder.h"

using namespace godot;

TowerBuilder::TowerBuilder()
{
	_loader = ResourceLoader::get_singleton();
	_tower_prefab = _loader->load("res://TD/Towers/TestTower.tscn");
	_tower = Object::cast_to<Area2D>(_tower_prefab->instance());
}

godot::TowerBuilder::~TowerBuilder()
{
	_tower = nullptr;
	_loader = nullptr;

	delete _tower;
	delete _loader;
}

Area2D* godot::TowerBuilder::get_tower()
{
	return _tower;
}

void godot::TowerBuilder::reset()
{
	_tower = Object::cast_to<Area2D>(_tower_prefab->instance());
}

void godot::TowerBuilder::_set_gun_sprite_01()
{
	_tower->call("_set_gun_path", "res://assets/MassiveMilitary/Images/Turret_2_0004_Bitmap------------------.png");
}

void godot::TowerBuilder::_set_base_sprite_01()
{
	_tower->call("_set_base_path", "res://assets/MassiveMilitary/Images/tower_1_0002_Package-----------------.png");
}

void godot::TowerBuilder::_set_attack_speed_low()
{
	_tower->call("_set_base_path", "res://assets/MassiveMilitary/Images/Turret_2_0004_Bitmap------------------.png");
}

void godot::TowerBuilder::_set_ammo_type_projectile01()
{
}


