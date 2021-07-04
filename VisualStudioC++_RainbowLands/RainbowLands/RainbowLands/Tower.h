#pragma once
#include <Godot.hpp>
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
		
		Vector2 _cell_size;
		Vector2 _cell_position;
		int _cell_id;
		String _current_tile;

		//shooting enemies logic
		Array _enemy_array;
		PathFollow2D* _current_target;
		Vector2 _target_position;

		//tower sprites
		Sprite* _base;
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
		void _on_aggro_area_entered(Area2D* _other_area);
		void _on_aggro_area_exited(Area2D* _other_area);
		void _on_tower_area_entered(Area2D* _other_area);
		void _on_tower_area_exited(Area2D* _other_area);
	};
}

