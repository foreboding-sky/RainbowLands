#pragma once
#include <Godot.hpp>
#include <Node.hpp>
#include <Object.hpp>
#include <Area2D.hpp>
#include <Texture.hpp>
#include <Sprite.hpp>
#include <SceneTree.hpp>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>
#include "Tower.h"
#include "ClosestNoLock.h"
#include <CircleShape2D.hpp>

namespace godot {
	class TowerBuilder
	{
		// variables
	private:
		ResourceLoader* loader;
		
		Area2D* tower;
		Ref<PackedScene> towerPrefab;
		// methods
	public:
		TowerBuilder();
		~TowerBuilder();

		// set gun sprites
		void SetGunSprite01();
		void SetGunSprite02();
		void SetGunSprite03();
		void SetGunSprite04();
		void SetGunSprite05();

		// set tower base platform sprites
		void SetPlatformSprite01();
		void SetPlatformSprite02();
		void SetPlatformSprite03();
		void SetPlatformSprite04();
		void SetPlatformSprite05();

		// set tower attack speed
		void SetAttackSpeedLow();
		void SetAttackSpeedNormal();
		void SetAttackSpeedHigh();
		void SetAttackSpeedVeryHigh();

		// set tower ammo type
		void SetAmmoTypeProjectile01();
		void SetAmmoTypeProjectile02();
		void SetAmmoTypeProjectile03();
		void SetAmmoTypeProjectile04();
		void SetAmmoTypeProjectile05();

		// set aggro range
		void SetShootingRangeShort();
		void SetShootingRangeNormal();
		void SetShootingRangeLong();

		// set tower placement cost
		void SetTowerPlacementCost30();
		void SetTowerPlacementCost50();
		void SetTowerPlacementCost70();
		void SetTowerPlacementCost120();
		void SetTowerPlacementCost200();

		// set tower targeting method
		void SetTargetingClosestNoLock();

		Area2D* Build();
		void Reset();
	};
}