#pragma once
#include <CanvasLayer.hpp>
#include <Godot.hpp>

namespace godot
{
	class UI : public  CanvasLayer
	{
		GODOT_CLASS(UI, CanvasLayer);

	public:
		static void _register_methods();
		void _init();
		void _ready();
		void _process(float delta);

		void on_coins_changed();
		void on_emeralds_changed();
		void on_health_changed();
		void on_wave_changed();

		static UI* get_singleon();

	private:
		static UI* _instance;
	};
}