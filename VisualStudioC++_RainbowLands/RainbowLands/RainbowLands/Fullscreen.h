#pragma once
#include <Godot.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <CheckButton.hpp>
#include "Global.h"

namespace godot
{
	class Fullscreen : public CheckButton
	{
		GODOT_CLASS(Fullscreen, CheckButton);

	public:
		static void _register_methods();
		void _init();
		void _ready();

		void OnButtonPressed();


	private:
		Global* global;
	};
}