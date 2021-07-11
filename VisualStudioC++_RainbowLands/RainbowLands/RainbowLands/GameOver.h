#pragma once
#include <Button.hpp>
#include <Godot.hpp>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include "LevelManager.h"
#include <Timer.hpp>
#include <string>
#include <String.hpp>

namespace godot
{
	class GameOver : public Node2D
	{
		GODOT_CLASS(GameOver, Node2D);

	public:
		static void _register_methods();
		void _init();
		void _ready();

		void OnTimerFinish();
		void SetScore(int value);
		void ShowScore();
		
	private:
		LevelManager* levelManager;
		Timer* timer;
		int score;
	};
}