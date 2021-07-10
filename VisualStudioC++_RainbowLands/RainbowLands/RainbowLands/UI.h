#pragma once
#include <CanvasLayer.hpp>
#include <Godot.hpp>
#include <Control.hpp>
#include <String.hpp>
#include <string>
#include "IObserver.h"
#include "ISubject.h"
#include "LevelManager.h"

namespace godot
{
	class UI : public  Control, public IObserver
	{
		GODOT_CLASS(UI, Control);

		// methods
	public:
		static void _register_methods();
		void _init();
		void _ready();
		void _process(float delta);

		void OnCoinsChanged(int value);
		void OnEmeraldsChanged(int value);
		void OnHealthChanged(int value);
		void OnWaveChanged();
		virtual void Update(Message& msg);

		// variables
	private:
		int waveCouner;
		LevelManager* levelManager;
	};
}