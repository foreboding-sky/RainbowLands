#include "Player.h"
#include <Input.hpp>

using namespace godot;

Player :: Player()
{
    _speed = 100;
}

Player::~Player()
{
}

void Player::_update(float delta)
{
    _motion = Vector2(0, 0);

    Input* i = Input::get_singleton();

    if (i->is_action_pressed("ui_up"))
        _motion.y -= _speed;
    if (i->is_action_pressed("ui_down"))
        _motion.y += _speed;
    if (i->is_action_pressed("ui_left"))
        _motion.x -= _speed;
    if (i->is_action_pressed("ui_right"))
        _motion.x += _speed;


    _motion = _motion.normalized() * _speed;
    move_and_slide(_motion);
}

void Player::_init()
{
}

void Player::_ready()
{
}

void Player::_register_methods()
{
	register_method((char*)"_update", &Player::_update);
	register_method((char*)"_init", &Player::_init);
	register_method((char*)"_ready", &Player::_ready);
}
