#include "Enemy1.h"

Enemy1 * Enemy1::create()
{
	auto enemy = new Enemy1();

	enemy->init();
	enemy->autorelease();

	return enemy;
}

bool Enemy1::init()
{
	Node::init();
	hitPoint = 100.0f;

	setContentSize(Size(100, 100));
	setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	auto enemy = Sprite::create("Enemy1.png");
	enemy->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	enemy->setPosition(100 / 2,100 / 2);
	addChild(enemy);


	auto move = MoveBy::create(1, Vec2(0,-100));
	auto rotate = RotateBy::create(1, -90);
	auto spawn = Spawn::create(move,rotate, nullptr);
	auto repeat = RepeatForever::create(spawn);
	runAction(repeat);

	return true;
}

void Enemy1::onHit()
{
	hitPoint -= 20.0f;
	if (hitPoint <= 0)
	{
		Dead();
	}
}

void Enemy1::Dead()
{
	isDead = true;
}

void Enemy1::Remove()
{
	if (isDead)
	{
		removeFromParent();
	}
}
