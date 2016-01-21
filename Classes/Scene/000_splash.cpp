#include "000_splash.h"
#include "001_init.h"
#include "../data_recources.h"

USING_NS_CC;

Scene* Scene_splash::createScene() {
	auto scene = Scene::create();
	auto layer = Scene_splash::create();
	scene->addChild(layer);
	return scene;
}

bool Scene_splash::init() {
	bool is_layer_setted = LayerColor::initWithColor(Color4B(0, 0, 0, 255));
	if (!is_layer_setted) return false;
	auto screenSize = Director::getInstance()->getWinSize();
	auto fadein = FadeIn::create(0.5f);
	auto fadeout = FadeOut::create(0.5f);
	auto next = CallFunc::create(CC_CALLBACK_0(Scene_splash::nextScene, this));
	auto seq = Sequence::create(fadein, DelayTime::create(1.0f), fadeout, next, NULL);
	auto splashImage = Sprite::create(resData::recources[resData::SPLASH_IMAGE]);
	splashImage->setAnchorPoint(Point(0, 1));
	splashImage->setOpacity(0.0f);
	splashImage->setPosition(Point(0, screenSize.height));
	this->addChild(splashImage);
	splashImage->runAction(seq);
	return true;
}

void Scene_splash::nextScene() {
	auto nextScene = Scene_init::createScene();
	Director::getInstance()->replaceScene(nextScene);
}