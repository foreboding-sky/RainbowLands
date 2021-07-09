#pragma once
#include <Button.hpp>
#include <Godot.hpp>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include "LevelManager.h"

namespace godot
{
	class StartWave : public Button
	{
		GODOT_CLASS(StartWave, Button);

	public:
		static void _register_methods();
		void _init();
		void _ready();

		void _on_button_pressed();

	private:
		LevelManager* levelManager;
	};
}