#include "Tower.h"

using namespace godot;

Tower::Tower()
{
    placementCost = 0;
    canBuild = false;
    isBuilding = true;
    isColliding = false;
    isAttacking = false;
    cellId = -1;

    attackSpeed = 1;
    baseSpritePath = "res://assets/MassiveMilitary/Images/tower_1_0002_Package-----------------.png";
    gunSpritePath = "res://assets/MassiveMilitary/Images/Turret_2_0004_Bitmap------------------.png";
}

Tower::~Tower()
{
    attackTimer = nullptr;
    input = nullptr;
    loader = nullptr;
    currentTarget = nullptr;
    tileMap = nullptr;
    gun = nullptr;
    base = nullptr;
    projectile = nullptr;

    delete attackTimer;
    delete input;
    delete loader;
    delete currentTarget;
    delete tileMap;
    delete gun;
    delete base;
    delete projectile;
}

void Tower::_register_methods()
{
    register_method((char*)"_physics_process", &Tower::_physics_process);
    register_method((char*)"_init", &Tower::_init);
    register_method((char*)"_ready", &Tower::_ready);
    
    register_method((char*)"_follow_mouse", &Tower::FollowMouse);
    register_method((char*)"_on_AttackSpeedTimer_timeout", &Tower::OnAttackSpeedTimerTimeout);
    register_method((char*)"_on_aggro_area_entered", &Tower::OnAggroAreaEntered);
    register_method((char*)"_on_aggro_area_exited", &Tower::OnAggroAreaExited);
    register_method((char*)"_on_tower_area_entered", &Tower::OnTowerAreaEntered);
    register_method((char*)"_on_tower_area_exited", &Tower::OnTowerAreaExited);

    register_method((char*)"_set_projectile_prefab", &Tower::SetProjectilePrefab);
    register_method((char*)"_set_gun_path", &Tower::SetGunPath);
    register_method((char*)"_set_base_path", &Tower::SetBasePath);
    register_method((char*)"_set_attack_speed", &Tower::SetAttackSpeed);
}

void Tower::_init()
{
}

void Tower::_ready()
{
    // get singletons
    loader = ResourceLoader::get_singleton();
    input = Input::get_singleton();
    levelManager = LevelManager::get_singleton();

    // set gun texture
    gun = cast_to<Sprite>(get_node("Gun"));
    Ref<Texture> _gun_texture = loader->load(gunSpritePath);
    gun->set_texture(_gun_texture);

    // set tower base(platform) texture
    base = cast_to<Sprite>(get_node("Base"));
    Ref<Texture> _base_texture = loader->load(baseSpritePath);
    base->set_texture(_base_texture);

    //set tower attack speed
    attackTimer = cast_to<Timer>(get_node("AttackSpeedTimer"));
    attackTimer->set_wait_time(attackSpeed);

    //set collider radius
    collisionShape = cast_to<CollisionShape2D>(get_node("Aggro")->get_child(0));
    collisionShape->set_shape((Ref<Shape2D>)circleShape);

    //get tilemap
    tileMap = cast_to<TileMap>(get_node("/root/main/tower_placement"));

    //set tile size
    cellSize = tileMap->get_cell_size();
    
    enemyArray.clear();
   
    //set projectile
    projectileSpawnPosition = Vector2(0, 0);
}

void Tower::_physics_process(float delta)
{
    //debug
    //std::string str = std::to_string(_enemy_array.size());
    //Godot::print(str.c_str());

     
    if (isBuilding)
    {
        FollowMouse();
        if (canBuild)
        {
            base->set_modulate(Color{ 0.0, 1.0, 0.0, 0.6 });
            gun->set_modulate(Color{ 0.0, 1.0, 0.0, 0.6 });
        }
        else
        {
            base->set_modulate(Color{ 1.0, 0.0, 0.0, 0.6 });
            gun->set_modulate(Color{ 1.0, 0.0, 0.0, 0.6 });
        }
        if (input->is_action_just_pressed("tower_build") && canBuild)
        {
            isBuilding = false;
            base->set_modulate(Color{ 1.0, 1.0, 1.0, 1.0 });
            gun->set_modulate(Color{ 1.0, 1.0, 1.0, 1.0 });
            levelManager->ChangeCurrency(placementCost * -1);
            targeting->SetTowerPosition(get_global_position());
        }
        if (input->is_action_just_pressed("cancel_tower_build"))
        {
            levelManager->ChangeCurrency(placementCost);
            queue_free();
        }
    }
    else
    {
        if (enemyArray.size() > 0)
        {
            targeting->SetEnemies(enemyArray);
            currentTarget = targeting->GetTarget();
            //getting target's global transform
            targetPosition = currentTarget->get_global_transform().get_origin();

            //rotation of the gun
            gun->set_rotation((targetPosition - get_position()).angle() + 1.5708);
            if (!isAttacking)
            {
                isAttacking = true;
                attackTimer->start(attackSpeed);
            }
        }
        else
        {
            //stop the attack timer, so the tower stops to attack
            attackTimer->stop();
            isAttacking = false;
        }
    }
}

//toewr follows mouse cursor in building mode and snaps to allowed tiles
void Tower::FollowMouse()
{
    set_position(get_global_mouse_position());
    cellPosition = Vector2(floor(get_position().x / cellSize.x),
        floor(get_position().y / cellSize.y));
    cellId = tileMap->get_cellv(cellPosition);
    if (cellId != -1 && !isColliding)
    {
        currentTile = tileMap->get_tileset().ptr()->tile_get_name(cellId);
        if (currentTile == "tower_base")
        {
            //snap tower to tile center
            set_position(Vector2{ (cellPosition.x * cellSize.x + cellSize.x / 2),
                                  (cellPosition.y * cellSize.y + cellSize.y / 2) });
            canBuild = true;
        }
    }
    else
    {
        canBuild = false;
    }
}

//attack target, spawn bullets(projectiles)
void Tower::OnAttackSpeedTimerTimeout()
{
    projectile = cast_to<Area2D>(projectilePrefab->instance());
    projectileSpawnPosition = cast_to<Node2D>(get_node("Gun/ShootPosition"))->get_global_transform().get_origin();
    projectile->set_position(projectileSpawnPosition);
    projectile->call("SetTarget", currentTarget);
    get_node("/root/main/projectiles")->add_child(projectile);
}

//enemy enters aggro range
void Tower::OnAggroAreaEntered(Area2D* _other_area)
{
    if (_other_area->is_in_group("Enemy"))
        enemyArray.append(_other_area->get_parent());
}

void Tower::OnAggroAreaExited(Area2D* _other_area)
{
    if (_other_area->is_in_group("Enemy"))
    {
        //if(_enemy_array.has(_other_area->get_parent()))
        enemyArray.erase(_other_area->get_parent());
        if (_other_area->get_parent() == currentTarget)
            currentTarget = nullptr;
    }
}

//trying to build tower on top of another tower
void Tower::OnTowerAreaEntered(Area2D* _other_area)
{
    if (_other_area->is_in_group("Tower"))
        isColliding = true;
}

void Tower::OnTowerAreaExited(Area2D* _other_area)
{
    if (_other_area->is_in_group("Tower"))
        isColliding = false;
}

//Tower setters
void Tower::SetProjectilePrefab(Ref<PackedScene> projectile)
{
    projectilePrefab = projectile;
}

void Tower::SetGunPath(String imagePath)
{
    gunSpritePath = imagePath;
}

void Tower::SetBasePath(String imagePath)
{
    baseSpritePath = imagePath;
}

void Tower::SetAttackSpeed(double atkSpeed)
{
    Godot::print("SetAttackSpeed");
    attackSpeed = atkSpeed;
}

void Tower::SetTowerCost(int cost)
{
    placementCost = cost;
}

void Tower::SetTargetingMethod(TargetingMethod* method)
{
    targeting = method;
}

void Tower::SetCollisionShape(Ref<CircleShape2D> shape)
{
    circleShape = shape;
}

int Tower::GetTowerPlacementCost()
{
    return placementCost;
}