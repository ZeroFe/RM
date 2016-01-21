#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Scene_init : public LayerColor {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Scene_init);
};
