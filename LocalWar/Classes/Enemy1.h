#pragma once
#include"cocos2d.h"

USING_NS_CC;

class Enemy1 : public Node
{
public:
	static Enemy1* create();
	bool init();
	void onHit();
	void Dead();
	void Remove();

private:
	bool isDead;
	float hitPoint;
};
