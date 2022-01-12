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
	//Sets up the player with x position, y position and the name of the player.
	Player* player = new Player(50, 50, "Player");

	//Sets the x scale and y scale.
	player->getTransform()->setScale({ 50,50 });
	//officially adds the actor into the game.
	addActor(player);
	
	

	////sets the ice cream cone to be the child of the player.
	//player->getTransform()->addChild(iceCream->getTransform());

	//sets up a circle collider for the player.
	CircleCollider* playerCollider = new CircleCollider(20, player);
	//adds in the collider
	player->setCollider(playerCollider);
	



	//Mr.Freeze (enemy) spawn info
	//sets up the enemy with x position, y position, name, and target.
	Enemies* enemy = new Enemies(600, 400, "Freeze", player);

	//sets the scale of the enemy
	enemy->getTransform()->setScale({ 100,100 });
	//Adds in the enemy
	addActor(enemy);
	//sets up a circle collider for the enemy to use
	CircleCollider* enemyCollider = new CircleCollider(20, enemy);
	//adds in the collider
	enemy->setCollider(enemyCollider);

	
}
