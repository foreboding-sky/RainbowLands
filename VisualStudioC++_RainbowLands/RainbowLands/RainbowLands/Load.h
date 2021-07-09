#pragma once
#include <Button.hpp>
#include <Godot.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>

namespace godot
{
	class Load : public Button
	{
		GODOT_CLASS(Load, Button);

	public:
		static void _register_methods();
		void _init();
		void _ready();
		void _load();
		void _on_button_pressed();
	private:
		bool _is_paused = false;
	};
}