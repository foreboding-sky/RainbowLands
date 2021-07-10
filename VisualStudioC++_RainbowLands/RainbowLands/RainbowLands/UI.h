#pragma once
#include <CanvasLayer.hpp>
#include <Godot.hpp>
#include <Control.hpp>
#include <String.hpp>
#include <string>

namespace godot
{
	class UI : public  Control
	{
		GODOT_CLASS(UI, Control);

	public:
		UI();
		~UI();

		static void _register_methods();
		void _init();
		void _ready();
		void _process(float delta);

		void on_coins_changed(int value);
		void on_emeralds_changed(int value);
		void on_health_changed(int value);
		void on_wave_changed(int value);

		static UI* get_singleon();

	private:
		static UI* _instance;
	};
}