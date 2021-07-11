#pragma once
#include <Godot.hpp>
#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <HSlider.hpp>
#include "Global.h"

namespace godot
{
	class MusicVolume : public HSlider
	{
		GODOT_CLASS(MusicVolume, HSlider);

	public:
		static void _register_methods();
		void _init();
		void _ready();

		void OnSliderMoved();


	private:
		Global* global;
	};
}