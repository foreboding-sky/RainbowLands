#pragma once
#include <Godot.hpp>
#include <Area2D.hpp>
#include <PathFollow2D.hpp>
#include <Array.hpp>
#include <memory>
#include <WeakRef.hpp>
#include <Reference.hpp>
#include "Enemy.h"

namespace godot {
	class AreaDamage : public Area2D
	{
		// methods
	private:
		GODOT_CLASS(AreaDamage, Area2D)
	public:
		AreaDamage();
		~AreaDamage();
		void _physics_process(float delta);
		void _init();
		void _ready();
		static void _register_methods();

		void OnEnemyAreaEntered(Area2D* otherArea);
		void OnSelfDestructTimeout();
		void SetTarget(PathFollow2D* target);

		// variables
	private:
		const double pi = 3.14159265359;

		int speed;
		int damage;

		bool canMove;

		double tickTime;
		double cooldownTimePassed;
		double selfDestructTime;

		Array enemies;
		NodePath targetPath;
		PathFollow2D* target;
		Vector2 targetPosition;
		Timer* selfDestruct;
		//std::weak_ptr<PathFollow2D> target_;
		Vector2 velocity;
		//collision
	};
}