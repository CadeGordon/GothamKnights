#include "MainScene.h"
#include "SpriteComponenet.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "Bullet.h"
#include "enemies.h"
#include "HealthComponent.h"
#include "CircleCollider.h"
#include "IceCream.h"




void MainScene::start()
{	
	//Red Hood (player) spawn info
	//Sets up the player with x position, y position and the name of the player.
	Player* player = new Player(50, 50, "Player");

	//Sets the x scale and y scale.
	player->getTransform()->setScale({ 50,50 });
	//officially adds the actor into the game.
	

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
	
	//sets up a circle collider for the enemy to use
	CircleCollider* enemyCollider = new CircleCollider(20, enemy);
	//adds in the collider
	enemy->setCollider(enemyCollider);



	////ice cream cone to child to Freeze
	
	


	Actor* child = new Actor(0, 0, "child");
	enemy->getTransform()->addChild(child->getTransform());
	child->getTransform()->setScale({ 50, 50 });
	CircleCollider* childCollider = new CircleCollider(30, child);
	child->setCollider(childCollider);

	IceCream* iceCream = new IceCream(.02f, -.02f, "IceCream");
	iceCream->getTransform()->setScale({ 50,50 });
	enemy->getTransform()->addChild(iceCream->getTransform());
	CircleCollider* iceCreamCollider = new CircleCollider(30, iceCream);
	iceCream->setCollider(iceCreamCollider);

	
	

	addActor(enemy);
	addActor(player);
	
	
}
