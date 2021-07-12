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
#include "LevelManager.h"
#include "UI.h"
#include "ISubject.h"

namespace godot
{
	class SpawnTower3 : public Button
	{
		GODOT_CLASS(SpawnTower3, Button);
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
		Ref<Texture> texture;
		Vector2 size;
		Ref<PackedScene> prefab = nullptr;
		Vector2 iconSize;
		LevelManager* levelManager;
	};
}