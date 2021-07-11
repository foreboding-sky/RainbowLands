#pragma once
#include <Godot.hpp>
#include "TagretingMethod.h"
#include <PathFollow2D.hpp>

namespace godot {
	class ClosestNoLock : public TargetingMethod
	{
	public:
		virtual ~ClosestNoLock() {}
		virtual void SetEnemies(Array enemies);
		virtual void SetTowerPosition(Vector2 pos);
		virtual PathFollow2D* GetTarget();
	};
}