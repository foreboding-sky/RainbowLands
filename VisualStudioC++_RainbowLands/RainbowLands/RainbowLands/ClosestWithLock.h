#pragma once
#include <Godot.hpp>
#include "TagretingMethod.h"
#include <PathFollow2D.hpp>

namespace godot {
	class ClosestWithLock : public TargetingMethod
	{
	protected:
		PathFollow2D* lockedTarget;
	public:
		ClosestWithLock();
		virtual ~ClosestWithLock();
		virtual void SetEnemies(Array enemies);
		virtual void SetTowerPosition(Vector2 pos);
		virtual PathFollow2D* GetTarget();
	};
}