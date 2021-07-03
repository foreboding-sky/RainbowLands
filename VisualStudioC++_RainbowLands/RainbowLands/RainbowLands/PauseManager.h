#pragma once
#include <Button.hpp>
#include <Godot.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <Input.hpp>

namespace godot
{
	class PauseManager : public Button
	{
		GODOT_CLASS(PauseManager, Button);

	public:
		static void _register_methods();
		void _init();
		void _ready();
		void _process(float delta);


	private:
		ResourceLoader* _resource_loader = nullptr;
		Input* _input = nullptr;
		Ref<PackedScene> pause_menu = nullptr;
	};
}