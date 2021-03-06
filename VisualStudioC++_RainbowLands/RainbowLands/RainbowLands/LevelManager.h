#pragma once
#include <Godot.hpp>
#include <Node.hpp>
#include <Timer.hpp>
#include <Array.hpp>
#include "ISubject.h"
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
#include "UI.h"
#include <SceneTree.hpp>
#include "Global.h"

namespace godot 
{
	class LevelManager : public Node, public ISubject
	{
		// methods
	private:
		GODOT_CLASS(LevelManager, Node)
	public:
		LevelManager();
		~LevelManager();
		static LevelManager* get_singleton();

		void _init();
		void _ready();
		static void _register_methods();

		void SpawnEnemy();
		void EndWave();
		void ButtonStartWave();
		void StartWave();
		void LoadEnemies();
		void MobDefeated(int amount);
		void ChangeCurrency(int amount);
		void MobGotThrough(int damage);
		void LevelOver();

		int waveCounter;
		int currency;

	private:
		// singleton
		static	LevelManager* instance;

		UI* ui;
		Button* startButton;
		RandomNumberGenerator* random;
		ResourceLoader* loader;
		Global* global;
		std::vector<Ref<PackedScene>> enemyRefs;
		PathFollow2D* enemy;
		Dictionary enemyThreat;
		int threatPool;
		int waveThreat;
		int increment;
		bool waveIsActive;
		Timer* spawnTimer;
		float currencyScaler;
		float currencyScalerIncrement;
		int currentHealth;
		int maxHealth;
		int score;
		int waveStartCounter;
	};
}