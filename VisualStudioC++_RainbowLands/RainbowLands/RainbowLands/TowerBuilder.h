#pragma once
#include <Godot.hpp>
#include <Object.hpp>
#include <Area2D.hpp>
#include <Texture.hpp>
#include <Sprite.hpp>
#include <SceneTree.hpp>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>
#include "Tower.h"

namespace godot {
	class TowerBuilder
	{
		// variables
	private:
		ResourceLoader* _loader;
		
		Area2D* _tower;
		Ref<PackedScene> _towerPrefab;
		// methods
	public:
		TowerBuilder();
		~TowerBuilder();
		// set gun sprites
		void SetGunSprite01();
		void SetGunSprite02();

		// set tower base platform sprites
		void SetPlatformSprite01();
		void SetPlatformSprite02();

		// set tower attack speed
		void SetAttackSpeedLow();
		void SetAttackSpeedHigh();

		// set tower ammo type
		void SetAmmoTypeProjectile01();
		void SetAmmoTypeProjectile02();

		Area2D* Build();
		void Reset();
	};
}