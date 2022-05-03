#include "PauseScene.h"
using namespace cocos2d;
Scene* PauseScene::createScene(RenderTexture* renderTexture)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();//获取当前尺寸
	//根据纹理renderTexture创建此场景背景精灵background
	Sprite* background=Sprite::createWithTexture(renderTexture->getSprite()->getTexture());
	background->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));//此精灵居中
    background->setFlippedY(true);//垂直翻转此精灵
	background->setColor(Color3B::GRAY);//此精灵灰色显示，也就是蒙上一层灰色膜
	PauseScene *pauseScene = PauseScene::create();//创建层
    pauseScene->addChild(background);
    return pauseScene;
}
 
bool PauseScene::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();//获取当前尺寸
	//创建一个纯文字按钮
    Label* label1 =Label::createWithSystemFont("=返回=", "Arial", 30);
    MenuItemLabel* menu_item_label1 = MenuItemLabel::create(label1,[&](Ref* pSender){
        Director::getInstance()->popScene();//本场景出栈
    });
	Menu* menu1 = Menu::create(menu_item_label1,NULL);
	menu1->setPosition(Vec2(visibleSize.width-menu_item_label1->getContentSize().width/2,menu_item_label1->getContentSize().height));//按钮的位置
	this->addChild(menu1,1);
	return true;
}
