#include "SoundPlaying.h"

namespace godot
{
	void SoundPlaying::_register_methods()
	{
		register_method("_init", &SoundPlaying::_init);
		register_method("_ready", &SoundPlaying::_ready);
		register_method("_on_button_pressed", &SoundPlaying::OnButtonPressed);
	}
	void SoundPlaying::_init()
	{

	}
	void SoundPlaying::_ready()
	{
		global = Global::get_singleton();
		set_pressed(global->GetSoundPlaying());
		connect("toggled", this, "_on_button_pressed");

	}
	void SoundPlaying::OnButtonPressed()
	{
		global->SetSoundPlaying(this->is_pressed());
	}
}

