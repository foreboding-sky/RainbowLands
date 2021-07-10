#include "LevelManager.h"

using namespace godot;

LevelManager* LevelManager::_instance = nullptr;

LevelManager::LevelManager() {}
LevelManager::~LevelManager() {}
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
	if (!_instance) _instance = new LevelManager();
	return _instance;
}

void LevelManager::LoadEnemies()
{
	enemyRefs.push_back(_loader->load("res://TD/Enemies/Enemy.tscn"));
	enemyThreat[enemyRefs[0]] = (int)1;
	enemyRefs.push_back(_loader->load("res://TD/Enemies/Bug.tscn"));
	enemyThreat[enemyRefs[1]] = (int)1;
	enemyRefs.push_back(_loader->load("res://TD/Enemies/Ancient.tscn"));
	enemyThreat[enemyRefs[2]] = (int)10;
	enemyRefs.push_back(_loader->load("res://TD/Enemies/AncientThreat.tscn"));
	enemyThreat[enemyRefs[3]] = (int)15;
	enemyRefs.push_back(_loader->load("res://TD/Enemies/BugExtreme.tscn"));
	enemyThreat[enemyRefs[4]] = (int)5;
	enemyRefs.push_back(_loader->load("res://TD/Enemies/CrystalAngel.tscn"));
	enemyThreat[enemyRefs[5]] = (int)4;
	enemyRefs.push_back(_loader->load("res://TD/Enemies/DeathAngel.tscn"));
	enemyThreat[enemyRefs[6]] = (int)8;
	enemyRefs.push_back(_loader->load("res://TD/Enemies/Defender.tscn"));
	enemyThreat[enemyRefs[7]] = (int)20;
	enemyRefs.push_back(_loader->load("res://TD/Enemies/Goliath.tscn"));
	enemyThreat[enemyRefs[8]] = (int)3;
	enemyRefs.push_back(_loader->load("res://TD/Enemies/MagmaGoliath.tscn"));
	enemyThreat[enemyRefs[9]] = (int)9;
	enemyRefs.push_back(_loader->load("res://TD/Enemies/Moth.tscn"));
	enemyThreat[enemyRefs[10]] = (int)35;
	enemyRefs.push_back(_loader->load("res://TD/Enemies/Overlord.tscn"));
	enemyThreat[enemyRefs[11]] = (int)30;
	enemyRefs.push_back(_loader->load("res://TD/Enemies/OverlordExtreme.tscn"));
	enemyThreat[enemyRefs[12]] = (int)100;
	enemyRefs.push_back(_loader->load("res://TD/Enemies/PenBot.tscn"));
	enemyThreat[enemyRefs[13]] = (int)25;
	enemyRefs.push_back(_loader->load("res://TD/Enemies/Stalker.tscn"));
	enemyThreat[enemyRefs[14]] = (int)2;
	enemyRefs.push_back(_loader->load("res://TD/Enemies/Sword.tscn"));
	enemyThreat[enemyRefs[15]] = (int)10;
	enemyRefs.push_back(_loader->load("res://TD/Enemies/Wasp.tscn"));
	enemyThreat[enemyRefs[16]] = (int)80;


}

void LevelManager::SpawnEnemy()
{
	while (waveThreat > 0)
	{
		int randomNumber = rand() % enemyRefs.size();
		int i = enemyThreat[enemyRefs[randomNumber]];
		spawnTimer->set_wait_time((float)i / 3.0);
		if (i <= waveThreat)
		{
			waveThreat -= i;
;
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
	waveIsActive = false;
	threatPool += increment++;
	spawnTimer->stop();
}
void LevelManager::StartWave()
{
	if (waveIsActive == false)
	{
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
	_loader = ResourceLoader::get_singleton();
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