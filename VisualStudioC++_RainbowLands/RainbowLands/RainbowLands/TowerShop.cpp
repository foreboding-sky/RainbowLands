#include "TowerShop.h"

namespace godot
{
	void TowerShop::_register_methods()
	{
		register_method("_init", &TowerShop::_init);
		register_method("_ready", &TowerShop::_ready);
		register_method("_on_button_pressed", &TowerShop::_on_button_pressed);
	}
	void TowerShop::_init()
	{

	}
	void TowerShop::_ready()
	{
		_visible = cast_to<CanvasItem>(get_child(0))->is_visible();
		get_child(0)->set("visible", _visible);
		connect("pressed", this, "_on_button_pressed");
	}
	void TowerShop::_on_button_pressed()
	{
		_visible = cast_to<CanvasItem>(get_child(0))->is_visible();

		if(_visible == true) Godot::print("True");
		else Godot::print("Not True");
		get_child(0)->set("visible", !_visible);	
	}
}

