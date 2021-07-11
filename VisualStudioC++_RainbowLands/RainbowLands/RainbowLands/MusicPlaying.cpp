#include "MusicPlaying.h"

namespace godot
{
	void MusicPlaying::_register_methods()
	{
		register_method("_init", &MusicPlaying::_init);
		register_method("_ready", &MusicPlaying::_ready);
		register_method("_on_button_pressed", &MusicPlaying::OnButtonPressed);
	}
	void MusicPlaying::_init()
	{

	}
	void MusicPlaying::_ready()
	{
		global = Global::get_singleton();
		set_pressed(global->GetMusicPlaying());
		connect("toggled", this, "_on_button_pressed");
		
	}
	void MusicPlaying::OnButtonPressed()
	{
		global->SetMusicPlaying(this->is_pressed());
	}
}

