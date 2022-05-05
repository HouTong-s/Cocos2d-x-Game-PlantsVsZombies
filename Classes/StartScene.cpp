#include "StartScene.h"
#include "ChooseDifficulty.h"
#include "Board/DataStructures.h"
USING_NS_CC;

Scene* StartScene::createScene()
{
    return StartScene::create();
}
bool StartScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto sprite = Sprite::create("背景.png");
    sprite->setContentSize(Size(ScreenWidth, ScreenHeight));
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);
    auto closeItem = MenuItemLabel::create(
                                           Label::createWithSystemFont("退出游戏", "Arial", 50),
                                           CC_CALLBACK_1(StartScene::menuCloseCallback, this));
    float x = origin.x + visibleSize.width/2 ;
    float y = origin.y + visibleSize.height/2 -40;
    closeItem->setPosition(Vec2(x,y));
    closeItem->setColor(Color3B::BLUE);
    
    auto StartItem = MenuItemLabel::create(
                                           Label::createWithSystemFont("开始游戏", "Arial", 50),
                                           CC_CALLBACK_1(StartScene::menuStartCallback, this));
    x = origin.x + visibleSize.width/2 ;
    y = origin.y + visibleSize.height/2 + 100;
    StartItem->setPosition(Vec2(x,y));
    StartItem->setColor(Color3B::BLUE);
    auto menu = Menu::create(closeItem,StartItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    return true;
}


void StartScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}
void StartScene::menuStartCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(ChooseDifficulty::createScene());
}
