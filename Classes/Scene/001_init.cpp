#include "Global.h"
#include "001_init.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* Scene_init::createScene() {
	auto scene = Scene::create();
	auto layer = Scene_init::create();
	scene->addChild(layer);
	return scene;
}

bool Scene_init::init() {
	bool is_layer_setted = LayerColor::initWithColor(Color4B(50, 21, 12, 255));
	if (!is_layer_setted) return false;

	return true;
}