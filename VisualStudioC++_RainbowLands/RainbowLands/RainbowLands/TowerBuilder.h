#pragma once
#include <Godot.hpp>
#include <Object.hpp>
#include <Area2D.hpp>
#include <Texture.hpp>
#include <Sprite.hpp>
#include <SceneTree.hpp>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>
#include "Tower.h"

namespace godot {
	class TowerBuilder
	{
		// variables
	private:
		ResourceLoader* _loader;

		Area2D* _tower;
		Ref<PackedScene> _tower_prefab;
		// methods
	public:
		TowerBuilder();
		~TowerBuilder();
		// set gun sprites
		void _set_gun_sprite_01();

		// set tower base platform sprites
		void _set_base_sprite_01();

		// set tower attack speed
		void _set_attack_speed_low();

		// set tower ammo type
		void _set_ammo_type_projectile01();

		Area2D* get_tower();
		void reset();
	};
}