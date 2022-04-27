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

#include "StartScene.h"
#include "ChooseDifficulty.h"
USING_NS_CC;

Scene* StartScene::createScene()
{
    return StartScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartSceneScene.cpp\n");
}

// on "init" you need to initialize your instance
bool StartScene::init()
{
    //////////////////////////////
    // 1. super init first
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
    
    // add a "close" icon to exit the progress. it's an autorelease object
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

    // 3. add your codes below...

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
