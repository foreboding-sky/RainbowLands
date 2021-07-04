#pragma once
#include <Godot.hpp>
#include <Area2D.hpp>
#include <PathFollow2D.hpp>

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

		void _set_target(PathFollow2D* target);

		// variables
	private:
		int _speed;
		PathFollow2D* _target;
		Vector2 _velocity;
		//collision
	};
}