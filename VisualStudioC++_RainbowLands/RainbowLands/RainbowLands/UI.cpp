#include "UI.h"

namespace godot
{
	UI* UI::_instance;

	UI::UI() {}
	UI::~UI() {}
	void UI::_register_methods()
	{
		register_method("_init", &UI::_init);
		register_method("_ready", &UI::_ready);
		register_method("_process", &UI::_process);
		register_method("on_coins_changed", &UI::on_coins_changed);
		register_method("on_emeralds_changed", &UI::on_emeralds_changed);
		register_method("on_health_changed", &UI::on_health_changed);
		register_method("on_wave_changed", &UI::on_wave_changed);
	}

	void UI::_init()
	{
		_instance = this;
	}
	void UI::_ready()
	{

	}
	void UI::_process(float delta)
	{

	}
	UI* UI::get_singleon()
	{
		return _instance;
	}
	void UI::on_coins_changed(int value)
	{
		std::string converter = std::to_string(value);
		String text = String(converter.c_str());
		this->get_node("/root/main/user_interface/gold")->set("text", text);
	}
	void UI::on_emeralds_changed(int value)
	{
		std::string converter = std::to_string(value);
		String text = String(converter.c_str());
		this->get_node("/root/main/user_interface/points")->set("text", text);
	}
	void UI::on_health_changed(int value)
	{
		std::string converter = std::to_string(value);
		String text = String(converter.c_str());
		this->get_node("/root/main/user_interface/lives")->set("text", text);
	}
	void UI::on_wave_changed(int value)
	{
		std::string converter = std::to_string(value);
		String text = String(converter.c_str());
		this->get_node("/root/main/user_interface/level")->set("text", text);
	}
}