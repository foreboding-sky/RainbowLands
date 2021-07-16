#pragma once
#include <Godot.hpp>
#include <Area2D.hpp>
#include <PathFollow2D.hpp>
#include <memory>
#include <WeakRef.hpp>
#include <Reference.hpp>
#include "Enemy.h"

namespace godot {
	class Projectile : public Area2D
	{
		// methods
	private:
		GODOT_CLASS(Projectile, Area2D)
	public:
		Projectile();
		~Projectile();
		void _physics_process(float delta);
		void _init();
		void _ready();
		static void _register_methods();

		void OnEnemyAreaEntered(Area2D* otherArea);
		void OnSelfDestructTimeout();
		void SetTarget(PathFollow2D* target);

		// variables
	private:
		bool hasTarget;
		int speed;
		int damage;
		NodePath targetPath;
		PathFollow2D* target;
		Timer* selfDestruct;
		//std::weak_ptr<PathFollow2D> target_;
		Vector2 velocity;
		//collision
	};
}