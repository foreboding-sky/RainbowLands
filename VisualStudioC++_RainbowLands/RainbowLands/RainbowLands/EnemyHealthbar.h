#pragma once
#include <Godot.hpp>
#include <SceneTree.hpp>
#include <Label.hpp>
#include "IObserver.h"
#include "ISubject.h"
#include <string>

namespace godot {
	class EnemyHealthbar : public Label, public IObserver
	{
		// methods
	private:
		GODOT_CLASS(EnemyHealthbar, Label)
	public:
		EnemyHealthbar();
		~EnemyHealthbar();

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