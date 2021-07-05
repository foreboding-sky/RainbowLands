#include "UI.h"

namespace godot
{
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
	}
	void UI::_ready()
	{
		
	}
	void UI::_process(float delta)
	{

	}
	//UI* UI::get_singleon()
	//{
	//	return _instance;
	//}
	void UI::on_coins_changed()
	{
		
	}
	void UI::on_emeralds_changed()
	{

	}
	void UI::on_health_changed()
	{

	}
	void UI::on_wave_changed()
	{

	}
}