#pragma once
#include"cocos2d.h"
#include"Cannon.h"
#include<vector>

USING_NS_CC;

class GameMain : public Scene
{
public:
	static GameMain* create();
	bool init();
	void update(float deltaTime) override;

private:
	void registerTouchEvent();
	void createEnemy();

private:
	std::vector<Cannon*> mCannons;
	
};
