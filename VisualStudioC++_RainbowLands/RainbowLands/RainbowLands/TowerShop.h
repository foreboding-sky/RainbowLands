#pragma once
#include <Button.hpp>
#include <Godot.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <Panel.hpp>
#include <CanvasItem.hpp>

namespace godot
{
	class TowerShop : public Button
	{
		GODOT_CLASS(TowerShop, Button);

	public:
		static void _register_methods();
		void _init();
		void _ready();

		void OnButtonPressed();

	private:
		bool visible;
	};
}