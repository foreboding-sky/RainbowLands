#pragma once
#include <Button.hpp>
#include <Godot.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include "Global.h"

namespace godot
{
	class Return : public Button
	{
		GODOT_CLASS(Return, Button);

	public:
		static void _register_methods();
		void _init();
		void _ready();

		void OnButtonPressed();


	private:
		ResourceLoader* _resource_loader = nullptr;
		Global* global;
	};
}