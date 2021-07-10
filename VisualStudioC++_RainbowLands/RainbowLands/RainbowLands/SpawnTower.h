#pragma once
#include <Button.hpp>
#include <Godot.hpp>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include <Area2D.hpp>
#include <Panel.hpp>
#include <Texture.hpp>
#include "TowerBuilder.h"

namespace godot
{
	class SpawnTower : public Button
	{
		GODOT_CLASS(SpawnTower, Button);
		// variables
	private:
		ResourceLoader* loader;
	public:
		static void _register_methods();
		void _init();
		void _ready();

		void OnMouseHovered();
		void OnMouseLeft();
		void OnButtonPressed();
		void BuildTower();

	
	private:
		Ref<Texture>_texture;
		Vector2 _size;
		Ref<PackedScene> prefab = nullptr;
		Vector2 _icon_size;
	};
}