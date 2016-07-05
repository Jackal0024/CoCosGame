#include "Cannon.h"
#include"Bullet.h"

Cannon * Cannon::create(std::string name)
{
	auto cannon = new Cannon();

	cannon->init(name);
	cannon->autorelease();

	return cannon;
}

bool Cannon::init(std::string name)
{
	Node::init();
	scheduleUpdate();

	isIdling = false;
	mIdlingTimer = 0.0f;
	mShotTimer = 0.0f;

	auto cannon = Sprite::create(name+".png");
	cannon->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	addChild(cannon);

	return true;
}

void Cannon::update(float deltaTime)
{
	if (isIdling)
	{
		mIdlingTimer += deltaTime;
	}
	else
	{
		mIdlingTimer -= deltaTime;
	}
	mIdlingTimer = std::min(std::max(mIdlingTimer, 0.0f), 0.5f);
	shot();
}

void Cannon::SetIdling(bool check)
{
	isIdling = check;
}

void Cannon::aim(Node * target)
{
	mSubVec = (target->getPosition() - getPosition()).getNormalized();

	float radian = atan2f(mSubVec.x, mSubVec.y);
	// ラジアンから度へ変換
	float angle = CC_RADIANS_TO_DEGREES(radian);

	// 0 ~ 360度に限定
	angle += 360;
	while (angle >= 360) {
		angle -= 360;
	}

	setRotation(angle);
}

void Cannon::shot()
{
	if (mIdlingTimer < 0.5f) return;
	if (mShotTimer < 0)
	{
		auto bullet = Bullet::create(mSubVec);
		bullet->setName("Bullet");
		bullet->setPosition(getPosition());
		getParent()->addChild(bullet);
		mShotTimer = 30;
	}
	mShotTimer -= 1;
}
