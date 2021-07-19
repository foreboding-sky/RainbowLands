#pragma once
#include <Godot.hpp>
#include <Position2D.hpp>
#include <Array.hpp>
#include <PathFollow2D.hpp>
#include "LevelManager.h"
#include <Label.hpp>
#include "ISubject.h"
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include "EnemyHealthbar.h"
#include <SceneTree.hpp>
#include "ISubject.h"
#include <Area2D.hpp>

namespace godot {
	class Enemy : public PathFollow2D, public ISubject
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

		void OnMouseHovered();
		void OnMouseLeft();
		void ScaleStats(float value);
		void TakeDamage(int damage);
		// variables
	private:
		
		int speed;
		int health;
		int maxHealth = 0;
		int damage;
		LevelManager* levelManager;
		ResourceLoader* loader;
		Ref<PackedScene> healthbarRef;
		EnemyHealthbar* healthbar;

	};
}