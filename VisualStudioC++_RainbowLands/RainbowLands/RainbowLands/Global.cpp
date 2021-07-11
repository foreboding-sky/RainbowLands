#include "Global.h"

using namespace godot;

Global* Global::_instance = nullptr;

Global::Global()
{
}

Global::~Global()
{

}

void Global::_register_methods()
{
	register_method("_physics_process", &Global::_physics_process);
	register_method("_init", &Global::_init);
	register_method("_ready", &Global::_ready);

}

void Global::SetMusicPlaying(bool value)
{
	musicPlaying = value;
	musicPlayer->_set_playing(musicPlaying);
}

bool godot::Global::GetMusicPlaying()
{
	return musicPlaying;
}

void Global::SetMusicVolume(float value)
{
	musicVolume = value;
	musicPlayer->set_volume_db(musicVolume);
}

float godot::Global::GetMusicVolume()
{
	return musicVolume;
}

void Global::SetSoundPlaying(bool value)
{
	soundPlaying = value;
}

bool godot::Global::GetSoundPlaying()
{
	return soundPlaying;
}

void Global::SetSoundVolume(float value)
{
	soundVolume = value;
}

float godot::Global::GetSoundVolume()
{
	return soundVolume;
}

void Global::SetFullscreen(bool value)
{
	fullscreen = value;
	os->set_window_fullscreen(fullscreen);
}

bool godot::Global::GetFullscreen()
{
	return fullscreen;
}

void godot::Global::SetBestScore(int value)
{
	bestScore = value;
}

Global* Global::get_singleton()
{
	if (!_instance) _instance = new Global();
	return _instance;
}


void Global::_ready()
{
	musicPlayer = cast_to<AudioStreamPlayer>(get_node("/root/Global/Music"));
	os = OS::get_singleton();
}

void Global::_physics_process(float delta)
{
}

void Global::_init()
{
	_instance = this;
}