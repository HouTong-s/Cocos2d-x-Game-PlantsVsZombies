/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "ChooseDifficulty.h"
#include "GameScene.h"
USING_NS_CC;

Scene* ChooseDifficulty::createScene()
{
    return ChooseDifficulty::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in ChooseDifficultyScene.cpp\n");
}

// on "init" you need to initialize your instance
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
                                           CC_CALLBACK_1(ChooseDifficulty::ChangeDifficultyCallback, this,40));
    x = origin.x + visibleSize.width/2 -150;
    y = origin.y + visibleSize.height/2 ;
    easyItem->setPosition(Vec2(x,y));
    easyItem->setColor(Color3B::BLUE);
    
    auto normalItem = MenuItemLabel::create(
                                           Label::createWithSystemFont("一般", "Arial", 50),
                                           CC_CALLBACK_1(ChooseDifficulty::ChangeDifficultyCallback, this,60));
    x = origin.x + visibleSize.width/2 ;
    y = origin.y + visibleSize.height/2 ;
    normalItem->setPosition(Vec2(x,y));
    normalItem->setColor(Color3B::BLUE);
    
    auto hardItem = MenuItemLabel::create(
                                           Label::createWithSystemFont("困难", "Arial", 50),
                                           CC_CALLBACK_1(ChooseDifficulty::ChangeDifficultyCallback, this,100));
    x = origin.x + visibleSize.width/2 + 150;
    y = origin.y + visibleSize.height/2 ;
    hardItem->setPosition(Vec2(x,y));
    hardItem->setColor(Color3B::BLUE);
    
    auto menu = Menu::create(easyItem,normalItem,hardItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    return true;
}

void ChooseDifficulty::ChangeDifficultyCallback(Ref* pSender,int num)
{
    Director::getInstance()->replaceScene(GameScene::createScene(num));
}
