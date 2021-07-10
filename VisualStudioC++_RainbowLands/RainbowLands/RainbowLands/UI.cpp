#include "UI.h"

namespace godot
{
	void UI::_register_methods()
	{
		register_method("_init", &UI::_init);
		register_method("_ready", &UI::_ready);
		register_method("_process", &UI::_process);
		register_method("on_coins_changed", &UI::OnCoinsChanged);
		register_method("on_emeralds_changed", &UI::OnEmeraldsChanged);
		register_method("on_health_changed", &UI::OnHealthChanged);
		register_method("on_wave_changed", &UI::OnWaveChanged);
	}

	void UI::Update(Message& msg)
	{
		switch (msg)
		{
			case WAVE_STARTED:
			{
				OnWaveChanged();
				break;
			}
			case DAMAGE_TAKEN:
			{
				OnHealthChanged(levelManager->currentHealth);
				break;
			}
			default:
				break;
		}
	}

	void UI::_init()
	{
		levelManager = LevelManager::get_singleton();
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
		this->get_node("/root/main/user_interface/gold")->set("text", text);
	}

	void UI::OnEmeraldsChanged(int value)
	{
		std::string converter = std::to_string(value);
		String text = String(converter.c_str());
		this->get_node("/root/main/user_interface/points")->set("text", text);
	}

	void UI::OnHealthChanged(int value)
	{
		std::string converter = std::to_string(value);
		String text = String(converter.c_str());
		this->get_node("/root/main/user_interface/lives")->set("text", text);
	}

	void UI::OnWaveChanged()
	{
		waveCouner++;
		std::string converter = "Wave: " + std::to_string(waveCouner);
		String text = String(converter.c_str());
		this->get_node("/root/main/UI/level")->set("text", text);
	}
	
}