#pragma once
#include <Godot.hpp>
#include <Position2D.hpp>
#include <Array.hpp>
#include <PathFollow2D.hpp>
#include "LevelManager.h"

namespace godot {
	class Enemy : public PathFollow2D
	{
		// methods
	private:
		GODOT_CLASS(Enemy, PathFollow2D)
	public:
		Enemy();
		~Enemy();

		static void _register_methods();
		void _physics_process(float delta);
		void _init();
		void _ready();

		void TakeDamage(int damage);
		// variables
	private:
		
		int speed;
		int health;
		int damage;
		LevelManager* levelManager;
	};
}