#include "MainScene.h"
#include "SpriteComponenet.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "Bullet.h"
#include "enemies.h"
#include "HealthComponent.h"
#include "CircleCollider.h"


void MainScene::start()
{	
	//Red Hood (player) spawn info

	Player* player = new Player(50, 50, "Player");
	

	player->getTransform()->setScale({ 50,50 });
	addActor(player);
	
	CircleCollider* playerCollider = new CircleCollider(20, player);
	player->setCollider(playerCollider);
	



	//Mr.Freeze (enemy) spawn info

	Enemies* enemy = new Enemies(600, 400, "Freeze", player);

	enemy->getTransform()->setScale({ 100,100 });
	addActor(enemy);
	CircleCollider* enemyCollider = new CircleCollider(20, enemy);
	enemy->setCollider(enemyCollider);
	
}
