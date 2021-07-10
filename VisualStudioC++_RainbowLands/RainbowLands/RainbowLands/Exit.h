#pragma once
#include <Button.hpp>
#include <Godot.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>

namespace godot
{
	class Exit : public Button
	{
		GODOT_CLASS(Exit, Button);

	public:
		static void _register_methods();
		void _init();
		void _ready();

		void OnButtonPressed();
	};
}