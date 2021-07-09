#include "TowerInfo.h"

namespace godot
{
	void TowerInfo::_register_methods()
	{
		register_method("_init", &TowerInfo::_init);
		register_method("_ready", &TowerInfo::_ready);

	}
	void TowerInfo::_init()
	{

	}
	void TowerInfo::_ready()
	{
		//connect("mouse_entered", this, "_on_mouse_hovered");
		//connect("mouse_exited", this, "_on_mouse_left");
	}

}

