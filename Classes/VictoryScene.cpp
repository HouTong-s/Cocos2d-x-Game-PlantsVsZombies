#include "VictoryScene.h"
#include "StartScene.h"
#include "Board/DataStructures.h"
USING_NS_CC;

Scene* VictoryScene::createScene()
{
    return VictoryScene::create();
}

bool VictoryScene::init()
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
    
    float x = origin.x + visibleSize.width/2 ;
    float y = origin.y + 2*visibleSize.height/3 ;
    
    auto label1 = Label::createWithSystemFont("恭喜你成功过关！", "Arial", 50);
    label1->setPosition(x,y);
    this->addChild(label1, 1);
    
    auto Item = MenuItemLabel::create(
                                    Label::createWithSystemFont("返回主菜单", "Arial", 50),
                                      [&](Ref* sender){
                                          Director::getInstance()->replaceScene(StartScene::create());
                                      });
    
    x = origin.x + visibleSize.width/2 ;
    y = origin.y + visibleSize.height/2 ;
    Item->setPosition(Vec2(x,y));
    Item->setColor(Color3B::BLUE);
    auto menu = Menu::create(Item, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    return true;
}
