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

namespace godot {
	class Tower : public Area2D
	{
		// variables
	public:
		TileMap* tileMap;
	private:
		GODOT_CLASS(Tower, Area2D)

		//tower placing logic
		bool isBuilding;
		bool canBuild;
		bool isColliding;
		
		Input* input;
		Vector2 cellSize;
		Vector2 cellPosition;
		int cellId;
		String currentTile;

		//attack speed
		double attackSpeed;
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

		//tower sprites
		String baseSpritePath;
		Sprite* base;
		String gunSpritePath;
		Sprite* gun;

		// methods
	public:
		Tower();
		~Tower();
		static void _register_methods();

		void _physics_process(float delta);
		void _init();
		void _ready();

		void FollowMouse();
		void OnAttackSpeedTimerTimeout();
		void OnAggroAreaEntered(Area2D* _other_area);
		void OnAggroAreaExited(Area2D* _other_area);
		void OnTowerAreaEntered(Area2D* _other_area);
		void OnTowerAreaExited(Area2D* _other_area);

		void SetProjectilePrefab(Ref<PackedScene> _projectile);
		void SetGunPath(String _iamge_path);
		void SetBasePath(String _iamge_path);
		void SetAttackSpeed(double _attck_speed);
	};
}

