#pragma once
#include <Godot.hpp>
#include <Node.hpp>
#include <TileMap.hpp>
#include <Timer.hpp>
#include <Input.hpp>
#include <InputEventMouseMotion.hpp>
#include <InputEventMouseButton.hpp>
#include <Position2D.hpp>
#include <Array.hpp>
#include <YSort.hpp>

namespace godot {
	class LevelManager : public Node
	{
		// methods
	private:
		GODOT_CLASS(LevelManager, Node)
	public:
		LevelManager();
		~LevelManager();
		void _process(float delta);
		void _init();
		void _ready();
		void _mob_got_through();
		void _level_over();
		void _unhandled_input(InputEvent event);
		static void _register_methods();

		// <- _mob_defeated here (!)

		// <- UI things here (!)

		// variables
	private:
		// wave of mobs management
		int _wave_counter;
		int _remaining_mobs_counter;
		int _max_waves;
		Timer* _mob_spawn_timer;

		// <- mob here (!)

		int _current_health;
		int _placement_currency;

		// tower management
		bool _can_place_tower;
		// tiles that you can't place tower on
		Array _invalid_tiles;
		TileMap* _tower_placement;
		YSort* _entities;
		// <- tower here (!)

		// <- UI here (!)
	};
}