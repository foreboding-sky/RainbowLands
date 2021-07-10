#include <Position2D.hpp>
#include <AnimationPlayer.hpp>
#include <Array.hpp>
#include <RandomNumberGenerator.hpp>
#include <PathFollow2D.hpp>
#include "LevelManager.h"

namespace godot {
	class Arrow : public PathFollow2D
	{
		// methods
	private:
		GODOT_CLASS(Arrow, PathFollow2D)
	public:
		Arrow();
		~Arrow();
		void _physics_process(float delta);
		void _init();
		void _ready();
		static void _register_methods();

		// variables
	private:
		int _speed;
	};
}