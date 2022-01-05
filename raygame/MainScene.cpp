#include "MainScene.h"
#include "SpriteComponenet.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "enemies.h"
#include "HealthComponent.h"
#include "CircleCollider.h"


void MainScene::start()
{	
	//Red Hood (player) spawn info

	Player* player = new Player(50, 50, "Player");

	player->getTransform()->setScale({ 50,50 });
	addActor(player);
	CircleCollider playerCollider = CircleCollider(20, player);

	*player->getCollider() = playerCollider;



	//Mr.Freeze spawn info

	Enemies* enemy = new Enemies(600, 400, "Freeze", player);

	enemy->getTransform()->setScale({ 100,100 });
	addActor(enemy);
	CircleCollider enemyCollider = CircleCollider(20, enemy);
	*enemy->getCollider() = enemyCollider;
	
	
}
