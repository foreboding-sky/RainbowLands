#pragma once
#include <Godot.hpp>
#include <Area2D.hpp>
#include <Vector2.hpp>
#include <TileMap.hpp>
#include <TileSet.hpp>
#include <String.hpp>

namespace godot {
	class Tower : public Area2D
	{
		// variables
	private:
		GODOT_CLASS(Tower, Area2D)

		//tower placing logic
		bool _is_in_building_mode;
		bool _can_build;
		bool _is_colliding;

		TileMap _tile_map;
		Vector2 _cell_size;
		Vector2 _cell_position;
		int _cell_id;
		String _current_tile;



		// methods
	public:
		Tower();
		~Tower();
		void _physics_process(float delta);
		void _init();
		void _ready();
		static void _register_methods();

		void _follow_mouse();
	};
}

