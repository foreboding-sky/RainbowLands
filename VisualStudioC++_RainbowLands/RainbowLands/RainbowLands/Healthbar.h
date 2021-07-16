#pragma once
#include <Godot.hpp>
#include <SceneTree.hpp>
#include <Label.hpp>
#include "IObserver.h"
#include "ISubject.h"
#include <string>

namespace godot {
	class Healthbar : public Label, public IObserver
	{
		// methods
	private:
		GODOT_CLASS(Healthbar, Label)
	public:
		Healthbar();
		~Healthbar();

		void _init();
		void _ready();
		void UpdateHealth(int health);
		void SetMaxHealth(int value);
		virtual void Update(Message& msg, int& param);

		static void _register_methods();
	private:

		int maxHealth = 0;


	};
}