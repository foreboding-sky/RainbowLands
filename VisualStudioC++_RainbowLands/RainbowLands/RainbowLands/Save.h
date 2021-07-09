#pragma once
#include <Button.hpp>
#include <Godot.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <File.hpp>
#include <Array.hpp>

namespace godot
{
	class Save : public Button
	{
		GODOT_CLASS(Save, Button);

	public:
		static void _register_methods();
		void _init();
		void _ready();
		void _save();
		void _on_button_pressed();
	private:
		bool _is_paused = false;
	};
}