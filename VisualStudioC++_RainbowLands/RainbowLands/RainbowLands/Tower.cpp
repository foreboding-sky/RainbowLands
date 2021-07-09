#include "Tower.h"

using namespace godot;

Tower::Tower()
{
    _can_build = false;
    _building_mode = true;
    _is_colliding = false;
    _is_attacking = false;
    _cell_id = -1;

    _attack_speed = 1;
    _projectile_prefab_path = "res://TD/Projectiles/Projectile_1.tscn";
    _base_sprite_path = "res://assets/MassiveMilitary/Images/tower_1_0002_Package-----------------.png";
    _gun_sprite_path = "res://assets/MassiveMilitary/Images/Turret_2_0004_Bitmap------------------.png";
}

Tower::~Tower()
{
    _loader = nullptr;
    _current_target = nullptr;
    _tile_map = nullptr;
    _gun = nullptr;
    _base = nullptr;
    _projectile = nullptr;
}

void Tower::_register_methods()
{
    register_method((char*)"_physics_process", &Tower::_physics_process);
    register_method((char*)"_init", &Tower::_init);
    register_method((char*)"_ready", &Tower::_ready);
    
    register_method((char*)"_follow_mouse", &Tower::_follow_mouse);
    register_method((char*)"_on_AttackSpeedTimer_timeout", &Tower::_on_AttackSpeedTimer_timeout);
    register_method((char*)"_on_aggro_area_entered", &Tower::_on_aggro_area_entered);
    register_method((char*)"_on_aggro_area_exited", &Tower::_on_aggro_area_exited);
    register_method((char*)"_on_tower_area_entered", &Tower::_on_tower_area_entered);
    register_method((char*)"_on_tower_area_exited", &Tower::_on_tower_area_exited);
    register_method((char*)"_set_projectile_path", &Tower::_set_projectile_prefab);
    register_method((char*)"_set_gun_path", &Tower::_set_gun_path);
    register_method((char*)"_set_base_path", &Tower::_set_base_path);
}

void Tower::_init()
{
}

void Tower::_ready()
{
    _loader = ResourceLoader::get_singleton();
    _input = Input::get_singleton();

    //set gun texture
    _gun = cast_to<Sprite>(get_node("Gun"));
    Ref<Texture> _gun_texture = _loader->load(_gun_sprite_path);
    _gun->set_texture(_gun_texture);

    //set tower base texture
    _base = cast_to<Sprite>(get_node("Base"));
    Ref<Texture> _base_texture = _loader->load(_base_sprite_path);
    _base->set_texture(_base_texture);

    //set tower attack speed
    _attack_timer = cast_to<Timer>(get_node("AttackSpeedTimer"));
    _attack_timer->set_wait_time(_attack_speed);

    //set collider radius (!)

    //get tilemap
    _tile_map = cast_to<TileMap>(get_node("/root/main/tower_placement"));

    //set tile size
    _cell_size = _tile_map->get_cell_size();
    
    _enemy_array.clear();
   
    //set projectile
    _projectile_prefab = _loader->load(_projectile_prefab_path);
    _projectile_spawn_position = Vector2(0, 0);
}

void Tower::_physics_process(float delta)
{
    //debug
    //std::string str = std::to_string(_enemy_array.size());
    //Godot::print(str.c_str());

     
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
        if (_input->is_action_just_pressed("tower_build") && _can_build)
        {
            _building_mode = false;
            _base->set_modulate(Color{ 1.0, 1.0, 1.0, 1.0 });
            _gun->set_modulate(Color{ 1.0, 1.0, 1.0, 1.0 });
            //subtract money from the wallet (!)
        }
        if (_input->is_action_just_pressed("cancel_tower_build"))
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
            _gun->set_rotation((_target_position - get_position()).angle() + 90);
            if (!_is_attacking)
            {
                _is_attacking = true;
                _attack_timer->start();
            }
        }
        else
        {
            //stop the attack timer, so the tower stops to attack
            _attack_timer->stop();
            _is_attacking = false;
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

//attack target, spawn bullets(projectiles)
void Tower::_on_AttackSpeedTimer_timeout()
{
	if (_current_target->is_inside_tree()) 
	{
		_projectile = cast_to<Area2D>(_projectile_prefab->instance());
		_projectile_spawn_position = cast_to<Node2D>(get_node("Gun/ShootPosition"))->get_global_transform().get_origin();
		_projectile->set_position(_projectile_spawn_position);
		_projectile->call("_set_target", _current_target);
		get_node("/root/main/projectiles")->add_child(_projectile);
	}
}

//toewr follows mouse cursor in building mode and snaps to allowed tiles
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
            //snap tower to tile center
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

//Tower setters
void Tower::_set_projectile_prefab(Ref<PackedScene> _projectile)
{
    _projectile_prefab = _projectile;
}

void Tower::_set_gun_path(String _iamge_path)
{
    _gun_sprite_path = _iamge_path;
}

void Tower::_set_base_path(String _iamge_path)
{
    _base_sprite_path = _iamge_path;
}

void godot::Tower::_set_attack_speed(double _attck_speed)
{
    _attack_speed = _attack_speed;
    _attack_timer->set_wait_time(_attack_speed);
}
