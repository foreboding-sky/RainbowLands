#pragma once
#include <Godot.hpp>
#include <Object.hpp>
#include <string>
#include <Area2D.hpp>
#include <Vector2.hpp>
#include <TileMap.hpp>
#include <TileSet.hpp>
#include <String.hpp>
#include <Sprite.hpp>
#include <Input.hpp>
#include <Array.hpp>
#include <PathFollow2D.hpp>
#include <SceneTree.hpp>
#include <Timer.hpp>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include "Projectile.h"
#include <Texture.hpp>

namespace godot {
	class Tower : public Area2D
	{
		// variables
	public:
		TileMap* _tile_map;
	private:
		GODOT_CLASS(Tower, Area2D)

		//tower placing logic
		bool _building_mode;
		bool _can_build;
		bool _is_colliding;
		
		Input* _input;
		Vector2 _cell_size;
		Vector2 _cell_position;
		int _cell_id;
		String _current_tile;

		//attack speed
		double _attack_speed;
		Timer* _attack_timer;

		//enemies
		Array _enemy_array;
		PathFollow2D* _current_target;
		Vector2 _target_position;

		//spawning projectiles
		ResourceLoader* _loader; 
		Ref<PackedScene> _projectile_prefab;
		String _projectile_prefab_path;
		Area2D* _projectile;
		Vector2 _projectile_spawn_position;
		bool _is_attacking;

		//tower sprites
		String _base_sprite_path;
		Sprite* _base;
		String _gun_sprite_path;
		Sprite* _gun;

		// methods
	public:
		Tower();
		~Tower();
		void _physics_process(float delta);
		void _init();
		void _ready();
		static void _register_methods();

		void _follow_mouse();
		void _on_AttackSpeedTimer_timeout();
		void _on_aggro_area_entered(Area2D* _other_area);
		void _on_aggro_area_exited(Area2D* _other_area);
		void _on_tower_area_entered(Area2D* _other_area);
		void _on_tower_area_exited(Area2D* _other_area);

		void _set_projectile_prefab(Ref<PackedScene> _projectile);
		void _set_gun_path(String _iamge_path);
		void _set_base_path(String _iamge_path);
		void _set_attack_speed(double _attck_speed);
	};
}

