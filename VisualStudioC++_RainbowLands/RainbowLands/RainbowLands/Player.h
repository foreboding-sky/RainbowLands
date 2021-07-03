#pragma once
#include <Godot.hpp>
#include <KinematicBody2D.hpp>
namespace godot {
	class Player : public KinematicBody2D
	{
	private:
		GODOT_CLASS(Player, KinematicBody2D)

		Vector2 _motion;
		float _speed;
	public:
		Player();
		~Player();
		void _update(float delta);
		void _init();
		void _ready();
		
		static void _register_methods();
	};
}

