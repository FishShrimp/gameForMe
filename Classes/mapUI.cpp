#include "mapUI.h"
#include "Hero.h"
#include "JoyStick.h"
#include "Common.h"
bool MapUI::init(String name)
{
	if (!Layer::init())
	{
		return false;
	}
	tmx = CCTMXTiledMap::create(name.getCString());
	this->addChild(tmx, 1, 10);
	Hero * hero = Hero::create();
	initHero(hero);
	setTouchEnabled(true);
	initScreen();
	return true;
}

MapUI* MapUI::create(String name)
{
	MapUI *mapUI = new MapUI;
	if (!mapUI->init(name))
	{
		return NULL;
	}
	mapUI->autorelease();

	return mapUI;
}

void MapUI::initHero(Sprite * hero)
{
	//��ȡTMX�ļ�
	TMXObjectGroup * objectGroup;
	objectGroup = tmx->objectGroupNamed("hero");
	
	if (objectGroup!=NULL)
	{
		ValueVector arrGroup = objectGroup->getObjects();
		int n = arrGroup.size();
		for (int k = 0; k < n;++k)
		{
			ValueMap objInfo = arrGroup.at(k).asValueMap();
			float x = objInfo.at("x").asFloat();
			float y = objInfo.at("y").asFloat();
			hero->setPosition(ccp(x, y));
			tmx->addChild(hero,127,"hero");
		}
	}
}

void MapUI::initJoyStick()
{

}

void MapUI::initScreen()
{
	Node *node = CSLoader::createNode("MainScene.csb");

	addChild(node,255);
}


