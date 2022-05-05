#include "ChooseDifficulty.h"
#include "GameScenes/GameScene.h"
USING_NS_CC;

Scene* ChooseDifficulty::createScene()
{
    return ChooseDifficulty::create();
}

bool ChooseDifficulty::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto sprite = Sprite::create("背景.png");
    sprite->setContentSize(Size(1422, 800));
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);
    
    float x = origin.x + visibleSize.width/2 ;
    float y = origin.y + 3*visibleSize.height/4 ;
    
    auto label1 = Label::createWithSystemFont("请选择难度", "Arial", 50);
    label1->setPosition(x,y);
    this->addChild(label1, 1);
    
    auto easyItem = MenuItemLabel::create(
                                           Label::createWithSystemFont("简单", "Arial", 50),
                                           CC_CALLBACK_1(ChooseDifficulty::ChooseDifficultyCallback, this,"easy",40));
    x = origin.x + visibleSize.width/2 -150;
    y = origin.y + visibleSize.height/2 ;
    easyItem->setPosition(Vec2(x,y));
    easyItem->setColor(Color3B::BLUE);
    
    auto normalItem = MenuItemLabel::create(
                                           Label::createWithSystemFont("一般", "Arial", 50),
                                           CC_CALLBACK_1(ChooseDifficulty::ChooseDifficultyCallback, this,"medium",60));
    x = origin.x + visibleSize.width/2 ;
    y = origin.y + visibleSize.height/2 ;
    normalItem->setPosition(Vec2(x,y));
    normalItem->setColor(Color3B::BLUE);
    
    auto hardItem = MenuItemLabel::create(
                                           Label::createWithSystemFont("困难", "Arial", 50),
                                           CC_CALLBACK_1(ChooseDifficulty::ChooseDifficultyCallback, this,"hard",100));
    x = origin.x + visibleSize.width/2 + 150;
    y = origin.y + visibleSize.height/2 ;
    hardItem->setPosition(Vec2(x,y));
    hardItem->setColor(Color3B::BLUE);
    
    auto menu = Menu::create(easyItem,normalItem,hardItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    return true;
}

void ChooseDifficulty::ChooseDifficultyCallback(Ref* pSender,std::string str,int num)
{
    try
    {
        auto scene = GameScene::createScene(str,num);
        Director::getInstance()->replaceScene(scene);
    }
    catch (const char *)
    {
        
    }
    
}
