#pragma once
#include <Button.hpp>
#include <Godot.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>

namespace godot
{
	class Options : public Button
	{
		GODOT_CLASS(Options, Button);

	public:
		static void _register_methods();
		void _init();
		void _ready();

		void OnButtonPressed();


	private:
		ResourceLoader* loader = nullptr;
	};
}