#pragma once
#include"cocos2d.h"

USING_NS_CC;

class Bullet : public Node
{
public:
	static Bullet* create(Vec2 velocity);
	bool init(Vec2 velocity);
	void update(float deltaTime) override;
	void Dead();
	void Remove();

private:
	Vec2 mVelocity;
	bool isDead;
};
