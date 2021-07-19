#pragma once
#include <Godot.hpp>
#include <Area2D.hpp>
#include <PathFollow2D.hpp>
#include <memory>
#include <WeakRef.hpp>
#include <Reference.hpp>
#include "Enemy.h"
#include <Particles2D.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>

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
		ResourceLoader* loader;
		NodePath targetPath;
		PathFollow2D* target;
		Timer* selfDestruct;

		//VFX
		Ref<PackedScene> refVFX;
		String pathVFX;
		Particles2D* VFX;

		//std::weak_ptr<PathFollow2D> target_;
		Vector2 velocity;
		//collision
	};
}