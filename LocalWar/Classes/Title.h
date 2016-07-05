#pragma once
#include"cocos2d.h"

USING_NS_CC;

class Title : public Scene
{
public:
	static Title* create();
	bool init();

private:
	void stateGame();

private:
};