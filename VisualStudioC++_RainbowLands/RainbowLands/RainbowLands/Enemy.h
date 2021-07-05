#pragma once
#include <Godot.hpp>
#include <Area2D.hpp>
#include <TileMap.hpp>
#include <Position2D.hpp>
#include <AnimationPlayer.hpp>
#include <Array.hpp>
#include <RandomNumberGenerator.hpp>
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
		void _physics_process(float delta);
		void _init();
		void _ready();
		static void _register_methods();

		// variables
	private:
		
		int _speed;
		int _health;
		int _damage;
		LevelManager* _level_manager = nullptr;
		//animations
		
		//collision
	};
}