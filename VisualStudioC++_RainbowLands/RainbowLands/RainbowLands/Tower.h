#pragma once
#include <Godot.hpp>
#include <Object.hpp>
#include <string>
#include <Area2D.hpp>
#include <Vector2.hpp>
#include <TileMap.hpp>
#include <TileSet.hpp>
#include <String.hpp>
#include <Sprite.hpp>
#include <Input.hpp>
#include <Array.hpp>
#include <PathFollow2D.hpp>
#include <SceneTree.hpp>
#include <Timer.hpp>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include "Projectile.h"
#include <Texture.hpp>
#include "LevelManager.h"
#include "ClosestNoLock.h"
#include <CircleShape2D.hpp>
#include <CollisionShape2D.hpp>
#include <Shape.hpp>

namespace godot {
	class Tower : public Area2D
	{
		GODOT_CLASS(Tower, Area2D)
		// variables
	private:
		//tower placing logic
		bool isBuilding;
		bool canBuild;
		bool isColliding;
		TileMap* tileMap;
		Input* input;
		Vector2 cellSize;
		Vector2 cellPosition;
		int cellId;
		String currentTile;
		int placementCost;
		LevelManager* levelManager;

		//attack speed
		double attackSpeed;
		float cooldownTimePassed;
		Timer* attackTimer;

		//enemies
		Array enemyArray;
		PathFollow2D* currentTarget;
		Vector2 targetPosition;

		//spawning projectiles
		ResourceLoader* loader; 
		Ref<PackedScene> projectilePrefab;
		String projectilePrefabPath;
		Area2D* projectile;
		Vector2 projectileSpawnPosition;
		bool isAttacking;
		TargetingMethod* targeting;
		CollisionShape2D* collisionShape;
		Ref<CircleShape2D> circleShape;

		//tower sprites
		String baseSpritePath;
		Sprite* base;
		String gunSpritePath;
		Sprite* gun;
		Sprite* attackRange;

		// methods
	public:
		Tower();
		~Tower();
		static void _register_methods();

		void _physics_process(float delta);
		void _init();
		void _ready();

		void FollowMouse();
		void DeleteTower();
		void OnAttackSpeedTimerTimeout();
		void OnAggroAreaEntered(Area2D* _other_area);
		void OnAggroAreaExited(Area2D* _other_area);
		void OnTowerAreaEntered(Area2D* _other_area);
		void OnTowerAreaExited(Area2D* _other_area);

		// setters
		void SetProjectilePrefab(Ref<PackedScene> projectile);
		void SetGunPath(String imagePath);
		void SetBasePath(String imagePath);
		void SetAttackSpeed(double atkSpeed);
		void SetTowerCost(int cost);
		void SetTargetingMethod(TargetingMethod* method);
		void SetCollisionShape(Ref<CircleShape2D> shape);

		// getters
		int GetTowerPlacementCost();
	};
}

