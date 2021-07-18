#include "UI.h"

namespace godot
{
	void UI::_register_methods()
	{
		register_method("_init", &UI::_init);
		register_method("_ready", &UI::_ready);
		register_method("_process", &UI::_process);
		register_method("on_coins_changed", &UI::OnCoinsChanged);
		register_method("on_emeralds_changed", &UI::OnScoreChanged);
		register_method("on_health_changed", &UI::OnHealthChanged);
		register_method("OnWaveStarted", &UI::OnWaveStarted);
		register_method("OnWaveEnded", &UI::OnWaveEnded);
	}

	void UI::Update(Message& msg, int& param)
	{
		switch (msg)
		{
			case WAVE_STARTED:
			{
				OnWaveStarted();
				break;
			}
			case WAVE_ENDED:
			{
				OnWaveEnded();
				break;
			}
			case DAMAGE_TAKEN:
			{
				OnHealthChanged(param);
				break;
			}
			case SCORE_GAINED:
			{
				OnScoreChanged(param);
				break;
			}
			case GOLD_GAINED:
			{
				OnCoinsChanged(param);
				break;
			}
			default:
				break;
		}
	}

	void UI::_init()
	{
		waveCouner = 0;
	}

	void UI::_ready()
	{
	}

	void UI::_process(float delta)
	{

	}

	void UI::OnCoinsChanged(int value)
	{
		std::string converter = std::to_string(value);
		String text = String(converter.c_str());
		this->get_node("/root/main/UI/gold")->set("text", text);
	}

	void UI::OnScoreChanged(int value)
	{
		std::string converter = "Score: " + std::to_string(value);
		String text = String(converter.c_str());
		this->get_node("/root/main/UI/points")->set("text", text);
	}

	void UI::OnHealthChanged(int value)
	{
		std::string converter = std::to_string(value);
		String text = String(converter.c_str());
		this->get_node("/root/main/UI/lives")->set("text", text);
	}

	void UI::OnWaveStarted()
	{
		waveCouner++;
		std::string converter = "Wave: " + std::to_string(waveCouner);
		String text = String(converter.c_str());
		this->get_node("/root/main/UI/level")->set("text", text);
		get_node("/root/main/UI/StartWave")->set("visible", false);
		converter = "In progress";
		text = String(converter.c_str());
		this->get_node("/root/main/UI/CanStart")->set("text", text);
	}
	void UI::OnWaveEnded()
	{
		get_node("/root/main/UI/StartWave")->set("visible", true);
		std::string converter = "Can Start";
		String text = String(converter.c_str());
		this->get_node("/root/main/UI/CanStart")->set("text", text);
	}
	
}