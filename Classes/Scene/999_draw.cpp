#include "Global.h"
#include "data_recources.h"
#include "999_draw.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
#define PTM_RATIO 32.0f
using namespace CocosDenshion;

Scene* Scene_draw::createScene() {
	auto scene = Scene::create();
	auto layer = Scene_draw::create();
	scene->addChild(layer);
	return scene;
}

bool Scene_draw::init() {
	bool is_layer_setted = LayerColor::initWithColor(Color4B(0, 0, 0, 255));
	if (!is_layer_setted) return false;

	/*���� �����*/
	b2Vec2 gravity = b2Vec2(0.0f, 0.0f);
	world_ = new b2World(gravity);

	/* ��ũ���� �°� body ����, edge shape�� �ܰ� 4���� fixture
	Body : static, dynamic, kinematic Ÿ��
	Shape : Circle, Polygon, Edge �� 2���� shape.
	Fixture : �е�(density), ������(friction), �ݹ߰��(restitution)�� ����. shape�� ���ε�.
	*/
	b2BodyDef screen_body_def;
	screen_body_def.position.Set(0.0f, 0.0f);

	b2Body *screen_body = world_->CreateBody(&screen_body_def);

	b2EdgeShape screen_edge;
	b2FixtureDef screen_fixture_def;

	screen_fixture_def.shape = &screen_edge; //shape ���ε�

	screen_edge.Set(b2Vec2(0.0f, 0.0f), b2Vec2(Global::screenSizeX / PTM_RATIO, 0));
	screen_body->CreateFixture(&screen_fixture_def);

	screen_edge.Set(b2Vec2(0.0f, 0.0f), b2Vec2(0, Global::screenSizeY / PTM_RATIO));
	screen_body->CreateFixture(&screen_fixture_def);

	screen_edge.Set(b2Vec2(0.0f, Global::screenSizeY / PTM_RATIO), b2Vec2(Global::screenSizeX / PTM_RATIO, Global::screenSizeY / PTM_RATIO));
	screen_body->CreateFixture(&screen_fixture_def);

	screen_edge.Set(b2Vec2(Global::screenSizeX / PTM_RATIO, Global::screenSizeY / PTM_RATIO), b2Vec2(Global::screenSizeX / PTM_RATIO, 0));
	screen_body->CreateFixture(&screen_fixture_def);

	/* �����Ӹ��� ��Ȳ�� ó���ϱ� ���� �����췯 ��� */
	this->schedule(schedule_selector(Scene_draw::tick));

	
	return true;
}

void tick(float dt) {

}

bool Scene_draw::onTouchBegan(Touch* touch, Event* event) {

	return true;
}

void Scene_draw::onTouchMoved(Touch* touch, Event* event) {
	
}

void Scene_draw::onTouchEnded(Touch* touch, Event* event) {
	// �ϳ��� ��������Ʈ�� ���� body ����
	// �̹��� ����
	Sprite *icon = Sprite::create(resData::recources[resData::PARTICLE_CLICK]);
}

void Scene_draw::ccTouchMoved(CCSet* touches, CCEvent* event) {

}


void Scene_draw::onEnter() {
	LayerColor::onEnter();	
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(Scene_draw::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(Scene_draw::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(Scene_draw::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void Scene_draw::onExit() {
	_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);
	LayerColor::onExit();
}

void Scene_draw::addRectangleBetweenPointsToBody(b2Body *body, CCPoint start, CCPoint end) {
	
}