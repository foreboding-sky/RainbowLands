#pragma once
#include <Godot.hpp>
#include <Node.hpp>
#include <SceneTree.hpp>
#include <AudioStreamPlayer.hpp>
#include <OS.hpp>

namespace godot
{
	class Global : public Node
	{

	private:
		GODOT_CLASS(Global, Node)
	public:
		Global();
		~Global();

		void _physics_process(float delta);
		void _init();
		void _ready();
		static void _register_methods();

		void SetMusicPlaying(bool value);
		bool GetMusicPlaying();
		void SetMusicVolume(float value);
		float GetMusicVolume();
		void SetSoundPlaying(bool value);
		bool GetSoundPlaying();
		void SetSoundVolume(float value);
		float GetSoundVolume();
		void SetFullscreen(bool value);
		bool GetFullscreen();

		static Global* get_singleton();

	private:

		OS* os;
		AudioStreamPlayer* musicPlayer;
		static	Global* _instance;


		float musicVolume = 1;
		float soundVolume = 1;
		float musicPlaying;
		bool soundPlaying;
		bool fullscreen;

	};
}