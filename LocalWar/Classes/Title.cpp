#include "Title.h"
#include"GameMain.h"

Title * Title::create()
{
	auto scene = new Title();

	scene->init();
	scene->autorelease();

	return scene;
}

bool Title::init()
{
	auto sprite = Sprite::create("TitleBG.png");
	sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	sprite->setPosition(0, 0);
	addChild(sprite);

	auto TitleLabel =
		Label::create("Gear Castle", "Marker Felt.ttf", 100);
	TitleLabel->setColor(Color3B::BLACK);
	TitleLabel->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	TitleLabel->setPosition(320, 700);
	addChild(TitleLabel);

	auto label =
		Label::create("Touch GameStart", "Marker Felt.ttf", 40);
	label->setColor(Color3B::BLACK);
	label->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	label->setPosition(320, 400);
	addChild(label);

	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan =
		[this](Touch* touch, Event* e)
	{
		stateGame();
		return true;
	};

	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void Title::stateGame()
{
	auto newScene = GameMain::create();
	auto transition = TransitionFade::create(1.0f, newScene);
	Director::getInstance()->replaceScene(transition);
}
