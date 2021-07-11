#include <ProgressBar.hpp>
#include <Godot.hpp>
#include <SceneTree.hpp>

namespace godot {
	class Healthbar : public ProgressBar
	{
		// methods
	private:
		GODOT_CLASS(Healthbar, ProgressBar)
	public:
		Healthbar();
		~Healthbar();
		void _init();
		void _ready();
		void SetValue(float value);

		static void _register_methods();

	};
}