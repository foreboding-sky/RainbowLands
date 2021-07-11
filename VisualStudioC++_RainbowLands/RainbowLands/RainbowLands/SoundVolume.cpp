#include "SoundVolume.h"

namespace godot
{
	void SoundVolume::_register_methods()
	{
		register_method("_init", &SoundVolume::_init);
		register_method("_ready", &SoundVolume::_ready);
		register_method("OnSliderMoved", &SoundVolume::OnSliderMoved);
	}
	void SoundVolume::_init()
	{

	}
	void SoundVolume::_ready()
	{
		global = Global::get_singleton();
		set_value(global->GetSoundVolume());
		connect("value_changed", this, "OnSliderMoved");

	}
	void SoundVolume::OnSliderMoved()
	{
		global->SetSoundVolume(get_value());
	}
}

