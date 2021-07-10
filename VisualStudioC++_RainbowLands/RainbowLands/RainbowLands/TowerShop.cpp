#include "TowerShop.h"

namespace godot
{
	void TowerShop::_register_methods()
	{
		register_method("_init", &TowerShop::_init);
		register_method("_ready", &TowerShop::_ready);
		register_method("_on_button_pressed", &TowerShop::OnButtonPressed);
	}
	void TowerShop::_init()
	{

	}
	void TowerShop::_ready()
	{
		visible = cast_to<CanvasItem>(get_child(0))->is_visible();
		get_child(0)->set("visible", visible);
		connect("pressed", this, "_on_button_pressed");
	}
	void TowerShop::OnButtonPressed()
	{
		visible = cast_to<CanvasItem>(get_child(0))->is_visible();

		if(visible == true) Godot::print("True");
		else Godot::print("Not True");
		get_child(0)->set("visible", !visible);
	}
}

