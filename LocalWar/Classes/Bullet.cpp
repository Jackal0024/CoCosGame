#include "Bullet.h"

Bullet * Bullet::create(Vec2 velocity)
{
	auto bullet = new Bullet();

	bullet->init(velocity);
	bullet->autorelease();

	return bullet;
}

bool Bullet::init(Vec2 velocity)
{
	Node::init();

	scheduleUpdate();
	mVelocity = velocity;

	auto bullet = Sprite::create("Bullet.png");
	bullet->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	bullet->setName("Bullet");

	float radian = atan2f(mVelocity.x, mVelocity.y);
	// ラジアンから度へ変換
	float angle = CC_RADIANS_TO_DEGREES(radian);

	// 0 ~ 360度に限定
	angle += 360;
	while (angle >= 360) {
		angle -= 360;
	}

	setRotation(angle);

	addChild(bullet);

	return true;
}

void Bullet::update(float deltaTime)
{
	auto position = getPosition() + mVelocity * 10;
	setPosition(position);

	if (getPosition().x < -20 || getPosition().x > 660)
	{
		removeFromParent();
	}
	else if(getPosition().y < -20 || getPosition().y > 980)
	{
		removeFromParent();
	}

}

void Bullet::Dead()
{
	isDead = true;
}

void Bullet::Remove()
{
	if (isDead)
	{
		removeFromParent();
	}
}
