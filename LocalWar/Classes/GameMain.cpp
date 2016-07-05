#include "GameMain.h"
#include"Bullet.h"
#include"Enemy1.h"

GameMain * GameMain::create()
{
	auto scene = new GameMain();
	
	scene->init();
	scene->autorelease();

	return scene;
}

bool GameMain::init()
{
	Scene::init();
	scheduleUpdate();

	auto sprite = Sprite::create("BG.png");
	sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	sprite->setPosition(0,0);
	addChild(sprite);

	auto line = Sprite::create("Line.png");
	line->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	line->setPosition(0, 200);
	addChild(line);

	//ƒLƒƒƒmƒ“----------------------------------------------

	auto cannon1 = Cannon::create("Cannon");
	cannon1->setName("Cannon");
	cannon1->setPosition(320, 150);
	addChild(cannon1);
	mCannons.push_back(cannon1);

	auto cannon2 = Cannon::create("Cannon");
	cannon2->setName("Cannon");
	cannon2->setPosition(220, 130);
	addChild(cannon2);
	mCannons.push_back(cannon2);

	auto cannon3 = Cannon::create("Cannon");
	cannon3->setName("Cannon");
	cannon3->setPosition(120, 100);
	addChild(cannon3);
	mCannons.push_back(cannon3);

	auto cannon4 = Cannon::create("Cannon");
	cannon4->setName("Cannon");
	cannon4->setPosition(420, 130);
	addChild(cannon4);
	mCannons.push_back(cannon4);

	auto cannon5 = Cannon::create("Cannon");
	cannon5->setName("Cannon");
	cannon5->setPosition(520, 100);
	addChild(cannon5);
	mCannons.push_back(cannon5);

	//---------------------------------------------------


	auto sights = Sprite::create("sights.png");
	sights->setName("Sights");
	sights->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	sights->setPosition(300,450);
	addChild(sights);

	schedule([this](float dt) {createEnemy(); }, 0.8f, "createEnemy");
	registerTouchEvent();

	return true;
}

void GameMain::update(float deltaTime)
{
	auto bullets = utils::findChildren(*this, "Bullet");
	auto enemys = utils::findChildren(*this, "Enemy");

	for (auto enemy : enemys)
	{
		if (enemy->getPosition().y < 200)
		{
			CCLOG("end");
		}
		for (auto bullet : bullets)
		{
			if (enemy->getBoundingBox().intersectsRect(bullet->getBoundingBox()))
			{
				CCLOG("hit");
				((Enemy1*)enemy)->onHit();
				((Bullet*)bullet)->Dead();
			}
		}
	}

	for (auto bullet : bullets)
	{
		((Bullet*)bullet)->Remove();
	}
	for (auto enemy : enemys)
	{
		((Enemy1*)enemy)->Remove();
	}
}

void GameMain::registerTouchEvent()
{
	auto listener = EventListenerTouchOneByOne::create();
	auto sights = getChildByName<Sprite*>("Sights");

	listener->onTouchBegan =
		[this,sights](Touch* touch, Event* e) 
	{
		sights->setPosition(touch->getLocation());

		for (auto cannon : mCannons)
		{
			cannon->aim(sights);
			cannon->SetIdling(true);
		}
		
		return true;
	};

	listener->onTouchMoved =
		[this, sights](Touch* touch, Event* e)
	{
		sights->setPosition(touch->getLocation());
		for (auto cannon : mCannons)
		{
			cannon->aim(sights);
		}

		return true;
	};

	listener->onTouchEnded =
		[this, sights](Touch* touch, Event* e)
	{
		sights->setPosition(touch->getLocation());
		for (auto cannon : mCannons)
		{
			cannon->aim(sights);
			cannon->SetIdling(false);
		}

		return true;
	};


	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(listener, this);
}

void GameMain::createEnemy()
{
	auto enemy = Enemy1::create();
	enemy->setName("Enemy");
	enemy->setPosition(rand() % 640, 960 + 50);
	addChild(enemy);
}

