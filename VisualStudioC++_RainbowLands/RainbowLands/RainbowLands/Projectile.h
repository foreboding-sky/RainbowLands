#pragma once
#include <Godot.hpp>
#include <Area2D.hpp>
#include <PathFollow2D.hpp>
#include <memory>
#include <WeakRef.hpp>
#include <Reference.hpp>

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

		void SetTarget(PathFollow2D* target);

		// variables
	private:
		int speed;
		NodePath targetPath;
		PathFollow2D* target;
		//std::weak_ptr<PathFollow2D> target_;
		Vector2 velocity;
		//collision
	};
}