#include "Godot.hpp"
#include "Play.h"
#include "Options.h"
#include "Exit.h"
#include "Return.h"
#include "PauseMenu.h"
#include "LevelManager.h"
#include "Enemy.h"
#include "Tower.h"
#include "SpawnTower1.h"
#include "SpawnTower2.h"
#include "SpawnTower3.h"
#include "SpawnTower4.h"
#include "SpawnTower5.h"
#include "UI.h"
#include "Resume.h"
#include "ToMain.h"
#include "TowerShop.h"
#include "Projectile.h"
#include "Arrow.h"
#include "GameOver.h"
#include "Global.h"
#include "MusicPlaying.h"
#include "MusicVolume.h"
#include "SoundPlaying.h"
#include "SoundVolume.h"
#include "Fullscreen.h"
#include "ReturnP.h"
#include "PauseOptions.h"
#include "PiercingProjectile.h"
#include "Healthbar.h"

using namespace godot;

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options * o) {
	Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options * o) {
	Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void* handle) {
	Godot::nativescript_init(handle);
	
	register_class<Play>();
	register_class<Options>();
	register_class<Exit>();
	register_class<Return>();
	register_class<PauseMenu>();
	register_class<Enemy>();
	register_class<LevelManager>();
	register_class<UI>();
	register_class<Tower>();
	register_class<SpawnTower1>();
	register_class<SpawnTower2>();
	register_class<SpawnTower3>();
	register_class<SpawnTower4>();
	register_class<SpawnTower5>();
	register_class<Resume>();
	register_class<ToMain>();
	register_class<TowerShop>();
	register_class<Projectile>();
	register_class<PiercingProjectile>();
	register_class<Arrow>();
	register_class<GameOver>();
	register_class<Global>();
	register_class<MusicPlaying>();
	register_class<MusicVolume>();
	register_class<SoundPlaying>();
	register_class<SoundVolume>();
	register_class<Fullscreen>();
	register_class<ReturnP>();
	register_class<PauseOptions>();
	register_class<Healthbar>();
}