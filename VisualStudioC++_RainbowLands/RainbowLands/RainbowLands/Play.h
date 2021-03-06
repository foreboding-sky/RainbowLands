#pragma once
#include <Button.hpp>
#include <Godot.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>

namespace godot
{
	class Play : public Button
	{
		GODOT_CLASS(Play, Button);

	public:
		static void _register_methods();
		void _init();
		void _ready();

		void _on_button_pressed();
		

	private:
		ResourceLoader* _resource_loader = nullptr;
	};
}