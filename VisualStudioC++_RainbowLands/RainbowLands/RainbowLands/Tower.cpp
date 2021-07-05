#include "Tower.h"

using namespace godot;

Tower::Tower()
{
}

Tower::~Tower()
{
    _current_target = nullptr;
    _tile_map = nullptr;
    _gun = nullptr;
    _base = nullptr;
}

void Tower::_register_methods()
{
    register_method((char*)"_physics_process", &Tower::_physics_process);
    register_method((char*)"_init", &Tower::_init);
    register_method((char*)"_ready", &Tower::_ready);

    register_method((char*)"_follow_mouse", &Tower::_follow_mouse);
    register_method((char*)"_on_aggro_area_entered", &Tower::_on_aggro_area_entered);
    register_method((char*)"_on_aggro_area_exited", &Tower::_on_aggro_area_exited);
    register_method((char*)"_on_tower_area_entered", &Tower::_on_tower_area_entered);
    register_method((char*)"_on_tower_area_exited", &Tower::_on_tower_area_exited);
}

void Tower::_init()
{
}

void Tower::_ready()
{
    _gun = cast_to<Sprite>(get_node("Gun"));
    _base = cast_to<Sprite>(get_node("Base"));

    //set collider radius (!)

    _tile_map = cast_to<TileMap>(get_node("/root/main/tower_placement"));
    _can_build = false;
    _building_mode = true;
    _is_colliding = false;
    _cell_size = _tile_map->get_cell_size();
    _cell_id = -1;
    _enemy_array.clear();
}

void Tower::_physics_process(float delta)
{
    //debug
    //std::string str = std::to_string(_enemy_array.size());
    //Godot::print(str.c_str());

    Input* i = Input::get_singleton();
    if (_building_mode)
    {
        _follow_mouse();
        if (_can_build)
        {
            _base->set_modulate(Color{ 0.0, 1.0, 0.0, 0.6 });
            _gun->set_modulate(Color{ 0.0, 1.0, 0.0, 0.6 });
        }
        else
        {
            _base->set_modulate(Color{ 1.0, 0.0, 0.0, 0.6 });
            _gun->set_modulate(Color{ 1.0, 0.0, 0.0, 0.6 });
        }
        if (i->is_action_just_pressed("tower_build") && _can_build)
        {
            _building_mode = false;
            _base->set_modulate(Color{ 1.0, 1.0, 1.0, 1.0 });
            _gun->set_modulate(Color{ 1.0, 1.0, 1.0, 1.0 });
            //subtract money from the wallet (!)
        }
        if (i->is_action_just_pressed("cancel_tower_build"))
        {
            queue_free();
        }
    }
    else
    {
        if (_enemy_array.size() > 0)
        {
            //getting target's global transform
            _current_target = _enemy_array[0];
            _target_position = _current_target->get_global_transform().get_origin();

            //rotation of the gun
            _gun->set_rotation((_target_position - get_position()).angle());

            //shooting logic (!)
        }
    }
}

//enemy enters aggro range
void Tower::_on_aggro_area_entered(Area2D* _other_area)
{
    if (_other_area->is_in_group("Enemy"))
        _enemy_array.append(_other_area->get_parent());
}

void Tower::_on_aggro_area_exited(Area2D* _other_area)
{
    if (_other_area->is_in_group("Enemy"))
    {
        //if(_enemy_array.has(_other_area->get_parent()))
        _enemy_array.erase(_other_area->get_parent());
        if (_other_area->get_parent() == _current_target)
            _current_target = nullptr;
    }
}

//trying to build tower on top of another tower
void Tower::_on_tower_area_entered(Area2D* _other_area)
{
    if (_other_area->is_in_group("Tower"))
        _is_colliding = true;
}

void Tower::_on_tower_area_exited(Area2D* _other_area)
{
    if (_other_area->is_in_group("Tower"))
        _is_colliding = false;
}

void Tower::_follow_mouse()
{
    set_position(get_global_mouse_position());
    _cell_position = Vector2(floor(get_position().x / _cell_size.x),
                             floor(get_position().y / _cell_size.y));
    _cell_id = _tile_map->get_cellv(_cell_position);
    if (_cell_id != -1 && !_is_colliding)
    {
        _current_tile = _tile_map->get_tileset().ptr()->tile_get_name(_cell_id);
        if (_current_tile == "tower_base")
        {
            //snap tower to cell center
            set_position(Vector2{ (_cell_position.x * _cell_size.x + _cell_size.x / 2),
                                  (_cell_position.y * _cell_size.y + _cell_size.y / 2) });
            _can_build = true;
        }
    }
    else
    {
        _can_build = false;
    }
}