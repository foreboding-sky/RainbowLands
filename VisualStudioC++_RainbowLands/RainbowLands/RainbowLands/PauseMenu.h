#pragma once
#include <Control.hpp>
#include <Godot.hpp>
#include <SceneTree.hpp>
#include <Input.hpp>
#include <InputEvent.hpp>

namespace godot
{
	class PauseMenu : public Control
	{
		GODOT_CLASS(PauseMenu, Control);

	public:
		static void _register_methods();
		void _init();
		void _ready();
		void _input(InputEvent* event);


	private:
		bool isPaused = false;
	};
}