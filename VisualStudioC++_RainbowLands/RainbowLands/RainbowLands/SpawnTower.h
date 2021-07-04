#pragma once
#include <Button.hpp>
#include <Godot.hpp>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include <Area2D.hpp>

namespace godot
{
	class SpawnTower : public Button
	{
		GODOT_CLASS(SpawnTower, Button);
		// variables
	private:
		ResourceLoader* _loader;
	public:
		static void _register_methods();
		void _init();
		void _ready();

		void _on_button_pressed();
	};
}