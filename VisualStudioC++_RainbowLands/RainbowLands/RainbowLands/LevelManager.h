#pragma once
#include <Godot.hpp>
#include <Node.hpp>
#include <Timer.hpp>
#include <Array.hpp>

namespace godot {
	class LevelManager : public Node
	{
		// methods
	private:
		GODOT_CLASS(LevelManager, Node)
	public:
		LevelManager();
		~LevelManager();

		void _physics_process(float delta);
		void _init();
		void _ready();
		static void _register_methods();

		void _mob_got_through();
		void _level_over();
		//static LevelManager* get_singleton();

		// <- UI things here (!) 

		// variables
	private:
		// singleton
		//static LevelManager* _instance;

		// wave of mobs management
		int _wave_counter;
		int _remaining_mobs_counter;
		int _max_waves;
		Timer* _mob_spawn_timer;
		// <- mob here (!)


		int _current_health;
		int _placement_currency;

		// <- UI here (!)
		
	};
}