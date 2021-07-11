#include "MusicVolume.h"

namespace godot
{
	void MusicVolume::_register_methods()
	{
		register_method("_init", &MusicVolume::_init);
		register_method("_ready", &MusicVolume::_ready);
		register_method("OnSliderMoved", &MusicVolume::OnSliderMoved);
	}
	void MusicVolume::_init()
	{

	}
	void MusicVolume::_ready()
	{
		global = Global::get_singleton();
		set_value(global->GetMusicVolume());
		connect("value_changed", this, "OnSliderMoved");

	}
	void MusicVolume::OnSliderMoved()
	{
		global->SetMusicVolume(get_value());
	}
}

