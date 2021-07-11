#pragma once
#include <Godot.hpp>
#include <Position2D.hpp>
#include <Array.hpp>
#include <PathFollow2D.hpp>
#include "LevelManager.h"
#include "Healthbar.h"

namespace godot {
	class Enemy : public PathFollow2D
	{
		// methods
	private:
		GODOT_CLASS(Enemy, PathFollow2D)
	public:
		Enemy();
		~Enemy();
		void _physics_process(float delta);
		void _init();
		void _ready();
		void TakeDamage(int damage);
		static void _register_methods();

		// variables
	private:
		
		int speed;
		int health;
		int maxHealth;
		int damage;
		LevelManager* levelManager;
		Healthbar* healthbar;
		//animations
		
		//collision
	};
}