#include "Tower.h"

using namespace godot;

void Tower::_register_methods()
{
    register_method((char*)"_physics_process", &Tower::_physics_process);
    register_method((char*)"_init", &Tower::_init);
    register_method((char*)"_ready", &Tower::_ready);
    register_method((char*)"_follow_mouse", &Tower::_follow_mouse);
}

Tower::Tower()
{
}

Tower::~Tower()
{
}

void Tower::_physics_process(float delta)
{
}

void Tower::_init()
{
}

void Tower::_ready()
{  
    _can_build = false;
    _is_in_building_mode = true;
    _is_colliding = false;
    _cell_size = _tile_map.get_cell_size();
}

void Tower::_follow_mouse()
{
    set_position(get_global_mouse_position());
    _cell_position = Vector2(floor(get_position().x / _cell_size.x),
                             floor(get_position().y / _cell_size.y));
    _cell_id = _tile_map.get_cellv(_cell_position);
    if (_cell_id != -1 && !_is_colliding)
    {
        _current_tile = _tile_map.get_tileset().ptr()->tile_get_name(_cell_id);
        if (_current_tile == "tower_base")
        {
            set_position(Vector2{ (_cell_position.x * _cell_size.x + _cell_size.x / 2),
                                  (_cell_position.y * _cell_size.y + _cell_size.y / 2) });
        }
    }
    else
    {
        _can_build = false;
    }
}