#include "ClosestWithLock.h"

using namespace godot;

godot::ClosestWithLock::ClosestWithLock()
{
	lockedTarget = nullptr;
}

godot::ClosestWithLock::~ClosestWithLock()
{
	lockedTarget = nullptr;
	delete lockedTarget;
}

void godot::ClosestWithLock::SetEnemies(Array enemies)
{
	enemyArray = enemies;
}

void godot::ClosestWithLock::SetTowerPosition(Vector2 pos)
{
	towerPosition = pos;
}

PathFollow2D* godot::ClosestWithLock::GetTarget()
{
	if (lockedTarget != nullptr && enemyArray.has(lockedTarget))
	{
		return lockedTarget;
	}
	PathFollow2D* tower = Object::cast_to<PathFollow2D>(enemyArray[0]);
	distanceToClosest = towerPosition.distance_to(tower->get_global_transform().get_origin());
	for (int i = 0; i < enemyArray.size(); i++)
	{
		auto distanceToEnemy = towerPosition.distance_to(Object::cast_to<PathFollow2D>(enemyArray[i])->get_global_transform().get_origin());
		if (distanceToEnemy < distanceToClosest)
		{
			distanceToClosest = distanceToEnemy;
			tower = Object::cast_to<PathFollow2D>(enemyArray[i]);
		}
	}
	lockedTarget = tower;
	return tower;
}