#include "SceneMgr.h"

MapUI* SceneMgr::mapUI = NULL;
SceneMgr* SceneMgr::sceneMgr = NULL;
void SceneMgr::changeScene(String name)
{
	//����TMX
	//�õ���ͼ��
	//��ʼ������

	mapUI->removeAllChildren();
	mapUI->init(name.getCString());
	JoyStick * joystick = JoyStick::create();
	mapUI->addChild(joystick, 128);
}

