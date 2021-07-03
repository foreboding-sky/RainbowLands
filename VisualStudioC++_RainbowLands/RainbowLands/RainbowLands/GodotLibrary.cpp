#include "Godot.hpp"
#include "Player.h"
#include "Play.h"
#include "Options.h"
#include "Exit.h"
#include "Return.h"

using namespace godot;

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options * o) {
	Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options * o) {
	Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void* handle) {
	Godot::nativescript_init(handle);
	
	register_class<Player>();
	register_class<Play>();
	register_class<Options>();
	register_class<Exit>();
	register_class<Return>();
}