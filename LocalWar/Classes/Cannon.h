#pragma once
#include"cocos2d.h"

USING_NS_CC;

class Cannon : public Node
{
public:
	static Cannon* create(std::string name);
	bool init(std::string name);
	void update(float deltaTime) override;

	void SetIdling(bool check);
	void aim(Node* target);
	void shot();

private:
	Vec2 mSubVec;
	float mIdlingTimer;
	float mShotTimer;
	bool isIdling;
};