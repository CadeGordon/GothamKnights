#include "MainScene.h"
#include "SpriteComponenet.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "Bullet.h"

void MainScene::start()
{
	Player* player = new Player(50, 50, "Player");
	Bullet* bullet = new Bullet(50, 50, "Bullet");
	

	player->getTransform()->setScale({ 50,50 });
	bullet->getTransform()->setScale({ 50,50 });
	addActor(player);
	addActor(bullet);
	
}
