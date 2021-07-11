#pragma once
#include <Godot.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <CheckButton.hpp>
#include "Global.h"

namespace godot
{
	class MusicPlaying : public CheckButton
	{
		GODOT_CLASS(MusicPlaying, CheckButton);

	public:
		static void _register_methods();
		void _init();
		void _ready();

		void OnButtonPressed();


	private:
		Global* global;
	};
}