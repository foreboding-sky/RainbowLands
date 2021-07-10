#include "LevelManager.h"

using namespace godot;

LevelManager* LevelManager::_instance;

LevelManager::LevelManager()
{
}

LevelManager::~LevelManager()
{
}
void LevelManager::Notify()
{

}
void LevelManager::_register_methods()
{
	register_method((char*)"_physics_process", &LevelManager::_physics_process);
	register_method((char*)"_init", &LevelManager::_init);
	register_method((char*)"_ready", &LevelManager::_ready);

	register_method((char*)"_mob_got_through", &LevelManager::_mob_got_through);
	register_method((char*)"_level_over", &LevelManager::_level_over);
	register_method("SpawnEnemy", &LevelManager::SpawnEnemy);
	register_method("LoadEnemies", &LevelManager::LoadEnemies);
	register_method("StartWave", &LevelManager::StartWave);
	register_method("EndWave", &LevelManager::EndWave);
}

LevelManager* LevelManager::get_singleton()
{
	return _instance;
	//return nullptr;
}

void LevelManager::LoadEnemies()
{
	enemyRefs.push_back(loader->load("res://TD/Enemies/Enemy.tscn"));
	enemyThreat[enemyRefs[0]] = (int)1;
}

void LevelManager::SpawnEnemy()
{
	Godot::print("entered");
	while (waveThreat > 0)
	{
		Godot::print("0");
		int randomNumber = rand() % enemyRefs.size();
		Godot::print("1");
		int i = enemyThreat[enemyRefs[randomNumber]];
		Godot::print("2");

		if (i <= waveThreat)
		{
			waveThreat -= i;
			spawnTimer->set_wait_time((float)i/3.0);
			enemy = cast_to<PathFollow2D>(enemyRefs[randomNumber]->instance());
			get_node("/root/main/Path2D")->add_child(enemy);
			break;
		}
	}
	if (waveThreat == 0)
	{
		EndWave();
	}
}

void LevelManager::EndWave()
{
	Godot::print("end");
	waveIsActive = false;
	threatPool += increment++;
	spawnTimer->stop();
}
void LevelManager::StartWave()
{
	if (waveIsActive == false)
	{
		Godot::print("start");
		waveIsActive = true;
		waveThreat = threatPool;
		spawnTimer->start();

	}
}
void LevelManager::_ready()
{
	std::srand(time(0));
	startButton = cast_to<Button>(get_node("/root/main/UI/StartWave"));
	startButton->connect("pressed", this, "StartWave");
	waveIsActive = false;
	loader = ResourceLoader::get_singleton();
	spawnTimer = cast_to<Timer>(get_node("/root/main/SpawnTimer"));
	spawnTimer->connect("timeout", this, "SpawnEnemy");
	threatPool = 5;
	increment = 1;
	_wave_counter = 0;
	_remaining_mobs_counter = 0;
	_max_waves = 10;
	_current_health = 10;
	_max_health = 10;
	_placement_currency = 10;
	LoadEnemies();
}

void LevelManager::_level_over()
{
	//level over logic
}

void LevelManager::_mob_got_through(int damage)
{
	if (_current_health <= 0)
		_level_over();
	else
		_current_health -= damage;
}

void LevelManager::_physics_process(float delta)
{
}

void LevelManager::_init()
{
	_instance = this;
}