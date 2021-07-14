#pragma once
#include <Godot.hpp>
#include <Node.hpp>
#include <SceneTree.hpp>
#include <AudioStreamPlayer.hpp>
#include <OS.hpp>
#include <Dictionary.hpp>
#include <Object.hpp>
#include <String.hpp>
#include <Variant.hpp>
#include <Array.hpp>
#include <File.hpp>
#include <JSON.hpp>
#include <JSONParseResult.hpp>

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

		void SetAllSettings();

		void SetScore(int value);

		int GetBestScore();
		int GetCurrentScore();

		void SaveScore();
		void SaveSettings();

		void Load();
		
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
		int bestScore = 0;
		int currentScore = 0;

	};
}