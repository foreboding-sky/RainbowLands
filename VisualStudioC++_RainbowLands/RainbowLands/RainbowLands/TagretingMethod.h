#pragma once
#include <Godot.hpp>
#include <PathFollow2D.hpp>
#include <Array.hpp>
#include <Vector2.hpp>
#include <Node.hpp>

namespace godot {
	class TargetingMethod
	{
	protected:
		Array enemyArray;
		double distanceToClosest;
		Vector2 towerPosition;
	public:
		TargetingMethod() {}
		virtual ~TargetingMethod() {}
		virtual void SetEnemies(Array enemies) = 0;
		virtual PathFollow2D* GetTarget() = 0;
		virtual void SetTowerPosition(Vector2 pos) = 0;
	};
}
