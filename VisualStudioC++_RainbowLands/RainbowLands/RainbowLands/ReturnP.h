#pragma once
#include <Button.hpp>
#include <Godot.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>

namespace godot
{
	class ReturnP : public Button
	{
		GODOT_CLASS(ReturnP, Button);

	public:
		static void _register_methods();
		void _init();
		void _ready();

		void OnButtonPressed();

	};
}