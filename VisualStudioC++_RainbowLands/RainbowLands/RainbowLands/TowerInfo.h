#pragma once
#include <Godot.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <Panel.hpp>
#include <Color.hpp>

namespace godot
{
	class TowerInfo : public Panel
	{
		GODOT_CLASS(TowerInfo, Panel);

	public:
		static void _register_methods();
		void _init();
		void _ready();

		void _on_mouse_hovered();
		void _on_mouse_left();

	};
}