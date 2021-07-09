#pragma once
#include <Godot.hpp>
#include <Node.hpp>
#include <Timer.hpp>
#include <Array.hpp>
#include "IObserver.h"
#include <PathFollow2D.hpp>
#include <vector>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <map>
#include <RandomNumberGenerator.hpp>
#include <random>
#include <Object.hpp>
#include <Button.hpp>
#include <time.h>

namespace godot 
{
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
		void SpawnEnemy();
		void EndWave();
		void StartWave();
		void LoadEnemies();
		void _mob_got_through(int damage);
		void _level_over();
		static LevelManager* get_singleton();

		int _wave_counter;
		int _remaining_mobs_counter;
		int _max_waves;
		Timer* spawnTimer;
		int _current_health;
		int _max_health;
		int _placement_currency;
	private:
		// singleton
		static	LevelManager* _instance;
		Button* startButton;
		RandomNumberGenerator* random;
		ResourceLoader* _loader;
		std::vector<Ref<PackedScene>> enemyRefs;
		PathFollow2D* enemy;
		Dictionary enemyThreat;
		int threatPool;
		int waveThreat;
		int increment;
		bool waveIsActive;
		// wave of mobs management

		// <- mob here (!)

		// <- UI here (!)
		
	};
}