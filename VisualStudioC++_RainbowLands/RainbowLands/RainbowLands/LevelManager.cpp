#include "LevelManager.h"

using namespace godot;

LevelManager* LevelManager::_instance = nullptr;

LevelManager* LevelManager::get_singleton()
{
	if (!_instance) _instance = new LevelManager();
	return _instance;
}

LevelManager::LevelManager()
{
}

LevelManager::~LevelManager() 
{
	DetachObserver((IObserver*)ui);
}

void LevelManager::_register_methods()
{
	register_method((char*)"_init", &LevelManager::_init);
	register_method((char*)"_ready", &LevelManager::_ready);

	register_method((char*)"_mob_got_through", &LevelManager::MobGotThrough);
	register_method((char*)"_level_over", &LevelManager::LevelOver);
	register_method("SpawnEnemy", &LevelManager::SpawnEnemy);
	register_method("LoadEnemies", &LevelManager::LoadEnemies);
	register_method("StartWave", &LevelManager::StartWave);
	register_method("EndWave", &LevelManager::EndWave);
}

void LevelManager::_init()
{
	_instance = this;
}

void LevelManager::_ready()
{
	//Godot::print("ready");
	global = Global::get_singleton();
	std::srand(time(0));
	ui = cast_to<UI>(get_node("/root/main/UI"));
	AttachObserver((IObserver*)ui);
	startButton = cast_to<Button>(get_node("/root/main/UI/StartWave"));
	startButton->connect("pressed", this, "StartWave");
	waveIsActive = false;
	loader = ResourceLoader::get_singleton();
	spawnTimer = cast_to<Timer>(get_node("/root/main/SpawnTimer"));
	spawnTimer->connect("timeout", this, "SpawnEnemy");
	threatPool = 5;
	increment = 1;
	waveCounter = 0;
	currentHealth = 1;
	maxHealth = 50;
	currency = 60;
	LoadEnemies();
}

void LevelManager::StartWave()
{
	if (waveIsActive == false)
	{
		waveCounter++;
		waveIsActive = true;
		waveThreat = threatPool;
		spawnTimer->start();
		Notify(Message::WAVE_STARTED);
	}
}

void LevelManager::EndWave()
{
	waveIsActive = false;
	threatPool += increment++;
	spawnTimer->stop();
	Notify(Message::WAVE_ENDED);
}

void LevelManager::SpawnEnemy()
{
	while (waveThreat > 0)
	{
		int randomNumber = rand() % enemyRefs.size();
		int i = enemyThreat[enemyRefs[randomNumber]];
		spawnTimer->set_wait_time(0.6f/((float)waveCounter / 2.0f) + (float)i / (3.0f + (float)waveCounter/2.0f));
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

void LevelManager::ChangeCurrency(int amount)
{
	currency += amount;
	Notify(Message::GOLD_GAINED, currency);
}

void LevelManager::MobDefeated(int amount)
{
	currency += amount;
	score += amount;
	Notify(Message::SCORE_GAINED, score);
	Notify(Message::GOLD_GAINED, currency);
}

void LevelManager::MobGotThrough(int damage)
{
	currentHealth -= damage;
	Notify(Message::DAMAGE_TAKEN, currentHealth);
	if (currentHealth <= 0)
		LevelOver();
}

void LevelManager::LevelOver()
{
	global->SetScore(score);
	get_tree()->change_scene("res://UI/GameOverScreen.tscn");
}

void LevelManager::LoadEnemies()
{
	enemyRefs.push_back(loader->load("res://TD/Enemies/Enemy.tscn"));
	enemyThreat[enemyRefs[0]] = (int)1;
	enemyRefs.push_back(loader->load("res://TD/Enemies/Bug.tscn"));
	enemyThreat[enemyRefs[1]] = (int)1;
	enemyRefs.push_back(loader->load("res://TD/Enemies/Ancient.tscn"));
	enemyThreat[enemyRefs[2]] = (int)10;
	enemyRefs.push_back(loader->load("res://TD/Enemies/AncientThreat.tscn"));
	enemyThreat[enemyRefs[3]] = (int)15;
	enemyRefs.push_back(loader->load("res://TD/Enemies/BugExtreme.tscn"));
	enemyThreat[enemyRefs[4]] = (int)5;
	enemyRefs.push_back(loader->load("res://TD/Enemies/CrystalAngel.tscn"));
	enemyThreat[enemyRefs[5]] = (int)4;
	enemyRefs.push_back(loader->load("res://TD/Enemies/DeathAngel.tscn"));
	enemyThreat[enemyRefs[6]] = (int)8;
	enemyRefs.push_back(loader->load("res://TD/Enemies/Defender.tscn"));
	enemyThreat[enemyRefs[7]] = (int)20;
	enemyRefs.push_back(loader->load("res://TD/Enemies/Goliath.tscn"));
	enemyThreat[enemyRefs[8]] = (int)3;
	enemyRefs.push_back(loader->load("res://TD/Enemies/MagmaGoliath.tscn"));
	enemyThreat[enemyRefs[9]] = (int)9;
	enemyRefs.push_back(loader->load("res://TD/Enemies/Moth.tscn"));
	enemyThreat[enemyRefs[10]] = (int)35;
	enemyRefs.push_back(loader->load("res://TD/Enemies/Overlord.tscn"));
	enemyThreat[enemyRefs[11]] = (int)30;
	enemyRefs.push_back(loader->load("res://TD/Enemies/OverlordExtreme.tscn"));
	enemyThreat[enemyRefs[12]] = (int)100;
	enemyRefs.push_back(loader->load("res://TD/Enemies/PenBot.tscn"));
	enemyThreat[enemyRefs[13]] = (int)25;
	enemyRefs.push_back(loader->load("res://TD/Enemies/Stalker.tscn"));
	enemyThreat[enemyRefs[14]] = (int)2;
	enemyRefs.push_back(loader->load("res://TD/Enemies/Sword.tscn"));
	enemyThreat[enemyRefs[15]] = (int)10;
	enemyRefs.push_back(loader->load("res://TD/Enemies/Wasp.tscn"));
	enemyThreat[enemyRefs[16]] = (int)80;
}