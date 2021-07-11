#include "GameOver.h"

namespace godot
{
	void GameOver::_register_methods()
	{
		register_method("_init", &GameOver::_init);
		register_method("_ready", &GameOver::_ready);
		register_method("OnTimerFinish", &GameOver::OnTimerFinish);
		register_method("SetScore", &GameOver::SetScore);
	}
	void GameOver::_init()
	{

	}
	void GameOver::_ready()
	{
		levelManager = LevelManager::get_singleton();
		timer = cast_to<Timer>(get_node("/root/Node2D/Timer"));
		timer->connect("timeout", this, "OnTimerFinish");
		ShowScore();
	}
	void GameOver::OnTimerFinish()
	{
		get_tree()->change_scene("res://MainMenu/MainMenu.tscn");
	}
	void GameOver::SetScore(int value)
	{
		score = value;
	}
	void GameOver::ShowScore()
	{
		std::string converter ="Final Score: " + std::to_string(score);
		String text = String(converter.c_str());
		this->get_node("/root/Node2D/BG/VBox/Score")->set("text", text);
		
	}
}

