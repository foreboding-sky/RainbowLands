#include "ClosestNoLock.h"

using namespace godot;

void godot::ClosestNoLock::SetEnemies(Array enemies)
{
	enemyArray = enemies;
}

void godot::ClosestNoLock::SetTowerPosition(Vector2 pos)
{
	towerPosition = pos;
}

PathFollow2D* godot::ClosestNoLock::GetTarget()
{
	PathFollow2D* enemy = Object::cast_to<PathFollow2D>(enemyArray[0]);
	distanceToClosest = towerPosition.distance_to(enemy->get_global_transform().get_origin());
	for (int i = 0; i < enemyArray.size(); i++)
	{
		auto distanceToEnemy = towerPosition.distance_to(Object::cast_to<PathFollow2D>(enemyArray[i])->get_global_transform().get_origin());
		if (distanceToEnemy < distanceToClosest)
		{
			distanceToClosest = distanceToEnemy;
			enemy = Object::cast_to<PathFollow2D>(enemyArray[i]);
		}
	}
	return enemy;
}