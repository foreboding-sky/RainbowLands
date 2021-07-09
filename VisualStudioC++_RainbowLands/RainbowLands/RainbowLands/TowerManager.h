#pragma once
#include <Godot.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <Panel.hpp>
#include <Color.hpp>
#include <Button.hpp>
#include "TowerBuilder.h"
namespace godot
{
	class TowerManager : public Panel
	{
		GODOT_CLASS(TowerManager, Panel);

	public:
		static void _register_methods();
		void _init();
		void _ready();

		void _on_mouse_hovered();
		void _on_mouse_left();

	private:
		Button* button = nullptr;
	};
}