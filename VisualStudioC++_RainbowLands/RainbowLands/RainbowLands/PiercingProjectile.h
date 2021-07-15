#pragma once
#include <Godot.hpp>
#include <Area2D.hpp>
#include <PathFollow2D.hpp>
#include <memory>
#include <WeakRef.hpp>
#include <Reference.hpp>
#include "Enemy.h"

namespace godot {
	class PiercingProjectile : public Area2D
	{
		// methods
	private:
		GODOT_CLASS(PiercingProjectile, Area2D)
	public:
		PiercingProjectile();
		~PiercingProjectile();
		void _physics_process(float delta);
		void _init();
		void _ready();
		static void _register_methods();

		void OnSelfDestructTimeout();
		void OnEnemyAreaEntered(Area2D* otherArea);
		void SetTarget(PathFollow2D* target);

		// variables
	private:
		int speed;
		int damage;
		Vector2 targetDirection;
		PathFollow2D* target;

		Timer* selfDestruct;
		//std::weak_ptr<PathFollow2D> target_;
		Vector2 velocity;
		//collision
	};
}