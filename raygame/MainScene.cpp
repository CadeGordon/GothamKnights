#include "MainScene.h"
#include "SpriteComponenet.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "enemies.h"
#include "HealthComponent.h"


void MainScene::start()
{	
	Player* player = new Player(50, 50, "Player");

	player->getTransform()->setScale({ 50,50 });
	addActor(player);

	Enemies* enemy = new Enemies(600, 400, "Freeze", player);

	enemy->getTransform()->setScale({ 100,100 });
	addActor(enemy);
	
	
	
}
