#include "LevelManager.h"

using namespace godot;

LevelManager::LevelManager()
{
	//_instance = this;
}

LevelManager::~LevelManager()
{
}

void LevelManager::_register_methods()
{
	register_method((char*)"_physics_process", &LevelManager::_physics_process);
	register_method((char*)"_init", &LevelManager::_init);
	register_method((char*)"_ready", &LevelManager::_ready);

	register_method((char*)"_mob_got_through", &LevelManager::_mob_got_through);
	register_method((char*)"_level_over", &LevelManager::_level_over);
}

//LevelManager* LevelManager::get_singleton()
//{
//	return _instance;
//}

void LevelManager::_ready()
{
	_wave_counter = 0;
	_remaining_mobs_counter = 0;
	_max_waves = 10;
	_current_health = 10;
	_placement_currency = 10;
}

void LevelManager::_level_over()
{
	//level over logic
}

void LevelManager::_mob_got_through()
{
	if (_current_health <= 0)
		_level_over();
	else
		_current_health -= 1;
}

void LevelManager::_physics_process(float delta)
{
}

void LevelManager::_init()
{
}