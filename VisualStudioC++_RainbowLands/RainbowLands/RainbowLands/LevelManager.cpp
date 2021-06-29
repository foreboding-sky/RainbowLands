#include "LevelManager.h"

using namespace godot;

LevelManager::LevelManager()
{
	_wave_counter = 0;
	_remaining_mobs_counter = 0;
	_max_waves = 10;
	_current_health = 10;
	_placement_currency = 10;
	_can_place_tower = false;
	_tower_placement = cast_to<TileMap>(get_node("tower_placement"));
	_invalid_tiles = cast_to<TileMap>(get_node("nav/tilemap_nav"))->get_used_cells();
	_entities = cast_to<YSort>(get_node("entities"));
}
LevelManager::~LevelManager()
{
}
void LevelManager::_level_over()
{
	//level over logic
}
void LevelManager::_mob_got_through()
{
	if (_current_health <= 0)
	{
		_level_over();
	}
	else
		_current_health -= 1;
}
void LevelManager::_unhandled_input(InputEvent e)
{
	//Input* i = Input::get_singleton();
	//check if event is InputEventMouseMotion (!)
	if (e == InputEventMouseMotion && _can_place_tower)
	{
		_tower_placement->clear();
		Vector2 tile = _tower_placement->world_to_map(e.position);// .position only works with InputEventMouse... types
		if (!_invalid_tiles.has(tile))
		{
			_tower_placement->set_cell(tile.x, tile.y, 0);
		}
		else
		{
			_tower_placement->set_cell(tile.x, tile.y, 1);
		}
	}
	else if(e == InputEventMouseButton && _can_place_tower && e.is_pressed())// e.pressed with InputEventMouse... types
	{
		Vector2 tile = _tower_placement->world_to_map(e.position);// .position only works with InputEventMouse... types
		if (!_invalid_tiles.has(tile))
		{
			_can_place_tower = false;
			_tower_placement->clear();

			_invalid_tiles.append(tile);

			// set _tower_instance
			//_entities->add_child(_tower_instance);
		}
	}
}
void LevelManager::_process(float delta)
{
}
void LevelManager::_init()
{
}
void LevelManager::_ready()
{
}
void LevelManager::_register_methods()
{
	register_method((char*)"_process", &LevelManager::_process);
	register_method((char*)"_init", &LevelManager::_init);
	register_method((char*)"_ready", &LevelManager::_ready); 
	register_method((char*)"_unhandled_input", &LevelManager::_unhandled_input);

	register_method((char*)"_mob_got_through", &LevelManager::_mob_got_through);
	register_method((char*)"_level_over", &LevelManager::_level_over);
}