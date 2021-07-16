#include "GameOver.h"

namespace godot
{
	void GameOver::_register_methods()
	{
		register_method("_init", &GameOver::_init);
		register_method("_ready", &GameOver::_ready);
		register_method("OnTimerFinish", &GameOver::OnTimerFinish);
	}
	void GameOver::_init()
	{

	}
	void GameOver::_ready()
	{
		global = Global::get_singleton();
		timer = cast_to<Timer>(get_node("/root/Node2D/Timer"));
		timer->connect("timeout", this, "OnTimerFinish");
		ShowScore();
	}
	void GameOver::OnTimerFinish()
	{
		get_tree()->change_scene("res://MainMenu/MainMenu.tscn");
	}

	void GameOver::ShowScore()
	{
		std::string converter ="Final Score: " + std::to_string(global->GetCurrentScore());
		String text = String(converter.c_str());
		this->get_node("/root/Node2D/BG/VBox/Score")->set("text", text);
		converter = "Best Score: " + std::to_string(global->GetBestScore());
		text = String(converter.c_str());
		this->get_node("/root/Node2D/BG/VBox/BestScore")->set("text", text);
	}
}

