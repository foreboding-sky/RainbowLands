#pragma once
#include <Godot.hpp>
#include <Node.hpp>
#include <Timer.hpp>
#include <Array.hpp>
#include "IObserver.h"

namespace godot {
	class LevelManager : public Node, IObserver
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

		virtual void Notify();
		void _mob_got_through(int damage);
		void _level_over();
		static LevelManager* get_singleton();

		int _wave_counter;
		int _remaining_mobs_counter;
		int _max_waves;
		Timer* _mob_spawn_timer;
		int _current_health;
		int _max_health;
		int _placement_currency;
	private:
		// singleton
	 static	LevelManager* _instance;

		// wave of mobs management

		// <- mob here (!)

		// <- UI here (!)
		
	};
}