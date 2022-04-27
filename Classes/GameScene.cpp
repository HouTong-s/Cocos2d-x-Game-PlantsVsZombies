//
//  GameScene.cpp
//  PlantsVsZombies
//
//  Created by houtong on 2022/4/24.
//
#include "GameScene.h"
#include"stdlib.h"
#include"Plants/AllPlants.h"
#include<math.h>
#include "AudioEngine.h"
#include "VictoryScene.h"
#include "DefeatScene.h"
#include "StartScene.h"
USING_NS_CC;
using namespace std;

Scene* GameScene::createScene(int num)
{
    auto scene = GameScene::create();
    scene->TotalZombies = scene->remainingZombies = scene->ZombiesToGenerate = num;
    return scene;
}
void GameScene::HandlePos(float x,float y)
{
    //CCLOG("HandlePos");
    if(this->Shovel->getBoundingBox().containsPoint(Vec2(x, y)))
    {
        this->whichCard = -10;
        return;
    }
    /*
    else if(this->Pause->getBoundingBox().containsPoint(Vec2(x, y)))
    {
        this->whichCard = -1;
        return;
    }
    else if(this->Shovel->getBoundingBox().containsPoint(Vec2(x, y)))
    {
        
    }
     */
    for(auto i=this->SunShapes.begin();i!=this->SunShapes.end();i++)
    {
        if((*i)->getBoundingBox().containsPoint(Vec2(x, y)))
        {
            this->whichCard = -1;
            return;
        }
    }
    for(int i=0;i<this->Row;i++)
        for(int j=0;j<this->Column;j++)
        {
            if(this->AllPieces[i][j]->getBoundingBox().containsPoint(Vec2(x, y)))
            {
                //this->whichCard = -1;
                return;
            }
        }
    for(auto i=0;i<this->AllCards.size();i++)
    {
        if(this->AllCards[i]->getBoundingBox().containsPoint(Vec2(x, y)))
        {
            if(TotalOfSun >= Plant::CardCost[i])
            {
                this->whichCard = i;
                return;
            }
        }
    }
    this->whichCard = -1;
}
MyRect GameScene::PosToPlant(float x,float y)
{
    //CCLOG("PosToPlant");
    MyRect result;
    for(int i=0;i<this->Row;i++)
        for(int j=0;j<this->Column;j++)
        {
            if(this->AllPieces[i][j]->getBoundingBox().containsPoint(Vec2(x, y)))
            {
                result.row = i;
                result.column = j;
                result.isLawn = true;
                return result;
            }
        }
    result.row = 0;
    result.column = 0;
    result.isLawn = false;
    return result;
}
void GameScene::PlantPlants(int row,int col)
{
    //CCLOG("PlantPlants");
    if(this->whichCard >=0)
    {
        for(int i=0;i<this->allLines[row]->plants.size();i++)
        {
            if(this->allLines[row]->plants[i]->column == col)
                return;
        }
        this->AllPieces[row][col]->setTexture(Plant::PlantsImgs[this->whichCard]);
        Plant* plant;
        switch (this->whichCard)
        {
            case 0:
                plant = new SunFlower(row, col, this->AllPieces[row][col]);
                break;
            case 1:
                plant = new PeaShooter(row, col, this->AllPieces[row][col]);
                break;
            case 2:
                plant = new IceShooter(row, col, this->AllPieces[row][col]);
                break;
            case 3:
                plant = new Nut(row, col, this->AllPieces[row][col]);
                break;
            case 4:
                plant = new PotatoMine(row, col, this->AllPieces[row][col]);
                break;
            case 5:
                plant = new DoubleShooter(row, col, this->AllPieces[row][col]);
                break;
            default:
                break;
        }
        if(plant!= nullptr)
        {
            this->AllPieces[row][col]->setContentSize(Size(101, 118));
            this->TotalOfSun -= Plant::CardCost[this->whichCard];
            this->allLines[row]->plants.push_back(plant);
        }
        this->whichCard = -1;
    }
    else if(this->whichCard == -10)
    {
        this->AllPieces[row][col]->setTexture("草地块.png");
        for(int i=0;i<this->allLines[row]->plants.size();i++)
        {
            if(this->allLines[row]->plants[i]->column == col)
            {
                delete this->allLines[row]->plants[i];
                this->allLines[row]->plants.erase(this->allLines[row]->plants.begin()+i);
            }
        }
        this->whichCard = -1;
    }
}
void GameScene::touchSun(float x,float y)
{
    //CCLOG("touchSun");
    auto i = this->SunShapes.begin();
    while (i!=this->SunShapes.end())
    {
        if((*i)->getBoundingBox().containsPoint(Vec2(x, y)))
        {
            this->TotalOfSun += 25;
            (*i)->removeFromParent();
            i = this->SunShapes.erase(i);
            break;
        }
        else
        {
            i++;
        }
    }
}
void GameScene::onMouseDown(Event *event)
{
    /*
     string str = "Mouse Down detected, Key: ";
     CCLOG("Mouse Down detected, Key: %s ", "left");
     */
    EventMouse* e = (EventMouse*)event;
    if(e->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT)
    {
        int x,y;
        x =e->getCursorX();
        y =e->getCursorY();
        touchSun(x, y);
        HandlePos(x, y);
        //CCLOG("onMouseDown");
        //CCLOG("%d", this->whichCard);
    }
}

void GameScene::onMouseUp(Event *event)
{
    //string str = "Mouse Up detected, Key: ";
    // CCLOG("Mouse Up detected, Key: %s ", "left");
    EventMouse* e = (EventMouse*)event;
    if(e->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT)
    {
        int x,y;
        x =e->getCursorX();
        y =e->getCursorY();
        MyRect rect = PosToPlant(x, y);
        if(rect.isLawn == true)
        {
            PlantPlants(rect.row, rect.column);
        }
        //CCLOG("onMouseUp");
    }
}

void GameScene::onMouseMove(Event *event)
{
    EventMouse* e = (EventMouse*)event;
    int x,y;
    x =e->getCursorX();
    y =e->getCursorY();
    if(e->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT)
    {
        touchSun(x, y);
    }
}

void GameScene::GenerateFlowerSunShape(float x,float y)
{
    //CCLOG("向日葵阳光");
    Sprite* sunNode = Sprite::create("阳光.png");
    this->SunShapes.pushBack(sunNode);
    sunNode->setPosition(x,y);
    sunNode->setContentSize(Size(75, 75));
    this->addChild(sunNode,100);
    sunNode->runAction(MoveBy::create(4, Vec2(0, -100)));
}

void GameScene::GenerateAutomaticSunShape()
{
    //CCLOG("天上的阳光");
    Sprite* sunNode = Sprite::create("阳光.png");
    srand(time(0));
    int x,y;
    x = rand()%MyLeft + MyLeft;
    y = rand()%(MyTop/2) - MyTop;
    sunNode->setPosition(x,780);
    sunNode->setContentSize(Size(75, 75));
    this->SunShapes.pushBack(sunNode);
    this->addChild(sunNode,100);
    sunNode->runAction(MoveBy::create(-y/30, Vec2(0, y)));
}

void GameScene::executeAll()
{
    for(int i=0;i<this->Row;i++)
    {
        auto j= this->allLines[i]->plants.begin();
        while (j != this->allLines[i]->plants.end())
        {
            if(!(*j)->execute(this))
            {
                (*j)->plantnode->setTexture("草地块.png");
                delete *j;
                j = this->allLines[i]->plants.erase(j);
            }
            else
            {
                j++;
            }
        }
        auto k= this->allLines[i]->zombies.begin();
        while (k != this->allLines[i]->zombies.end())
        {
            if(!(*k)->move(this->allLines))
            {
                this->remainingZombies -=1;
                (*k)->zombienode->removeFromParent();
                delete *k;
                k = this->allLines[i]->zombies.erase(k);
            }
            else
            {
                k++;
            }
        }
    }
    auto i=this->allProps.begin();
    while (i!=this->allProps.end())
    {
        if(!(*i)->execute(this))
        {
            //(*i)->plantnode->removeFromParent();
            i = this->allProps.erase(i);
        }
        else
        {
            i++;
        }
    }
}
void GameScene::JudgeIsFailed()
{
    for(int i=0;i<this->Row;i++)
        for(auto j=this->allLines[i]->zombies.begin();j!=this->allLines[i]->zombies.end();j++)
        {
            if((*j)->zombienode != nullptr && (*j)->zombienode->getPosition().x < MyLeft - 30)
            {
                Director::getInstance()->replaceScene(DefeatScene::create());
                break;
            }
        }
}
void GameScene::update(float dt)
{
    if(this->remainingZombies <= 0)
    {
        Director::getInstance()->replaceScene(VictoryScene::create());
    }
    JudgeIsFailed();
    this->SunNumNode->setString(to_string(this->TotalOfSun));
    this->remainingZombiesNum->setString(to_string(this->remainingZombies));
    executeAll();
    auto end = chrono::system_clock::now();
    chrono::duration<double> diff = end - this->start;
    //CCLOG("%f %f",diff.count(),remainder);
    if(diff.count()>3.99)
    {
        this->start = end;
        GenerateAutomaticSunShape();
    }
    //以下生成僵尸
    this->zombiesgenerator.execute(this, end);
}

bool GameScene::init()
{
    //chrono::system_clock::time_point start = chrono::system_clock::now();

    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    //初始化数据
    for(int i=0;i<this->Row;i++)
    {
        this->allLines.push_back(new Line());
    }
    this->AllPieces.resize(this->Row,vector<Sprite*>(this->Column,nullptr));
    this->start = chrono::system_clock::now();
    
    //注册鼠标事件
    auto _mouseListener = EventListenerMouse::create();
    _mouseListener->onMouseMove = CC_CALLBACK_1(GameScene::onMouseMove, this);
    _mouseListener->onMouseUp = CC_CALLBACK_1(GameScene::onMouseUp, this);
    _mouseListener->onMouseDown = CC_CALLBACK_1(GameScene::onMouseDown, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
    
    //播放背景音乐
    backgroundAudioID = AudioEngine::play2d("music/BackGroundMusic.mp3", true);
    
    //
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // 添加背景图片
    auto sprite = Sprite::create("背景.png");
    //CCLOG( "content size: %f %f",sprite->getContentSize().height,sprite->getContentSize().width);
    sprite->setContentSize(Size(1422, 800));
    //CCLOG( "content size: %f %f",sprite->getContentSize().height,sprite->getContentSize().width);
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);
    //添加卡片
    for(int i=0;i<Plant::CardImgs.size();i++)
    {
        
        auto cardTemp = Sprite::create(Plant::CardImgs[i]);
        cardTemp->setPosition(265, 684-i*100);
        //getBoundingBox获取节点在父坐标系的矩形框坐标
        /*
        Rect myrec =  cardTemp->getBoundingBox();
        CCLOG("%f %f %f %f",myrec.getMinX(),myrec.getMinY(),myrec.getMaxX(),myrec.getMaxY());
         */
        this->AllCards.push_back(cardTemp);
        this->addChild(cardTemp);
    }
    //添加草地块
    for(int i=0;i<5;i++)
        for(int j=0;j<9;j++)
        {
            auto plantTemp = Sprite::create("草地块.png");
            plantTemp->setPosition(MyLeft+101*j, MyTop-118*i);
            plantTemp->setAnchorPoint(Vec2(0, 1));
            plantTemp->setContentSize(Size(101, 118));
            this->AllPieces[i][j] = plantTemp;
            this->addChild(plantTemp);
        }
    //添加阳光值
    auto SunCard = Sprite::create("阳光1.png");
    SunCard->setPosition(95, 624);
    SunCard->setContentSize(Size(110, 110));
    this->addChild(SunCard);
    
    auto BlackBack =Sprite::create("土豆地雷卡.png");
    BlackBack->setPosition(95, 520);
    BlackBack->setOpacity(200);
    BlackBack->setColor(Color3B(0, 0, 0));
    BlackBack->setContentSize(Size(140, 55));
    this->addChild(BlackBack);
    
    auto label = Label::createWithSystemFont("0", "Arial", 50);
    this->SunNumNode = label;
    label->setPosition(95,520);
    this->addChild(label, 1);
    
    //其他的按钮
    auto shovelNode = Sprite::create("铲子.png");
    shovelNode->setPosition(60, 60);
    shovelNode->setContentSize(Size(90, 90));
    this->addChild(shovelNode);
    this->Shovel = shovelNode;
    
    /*
    auto pauseNode = Sprite::create("暂停.png");
    pauseNode->setPosition(1300, 750);
    pauseNode->setContentSize(Size(70, 70));
    this->addChild(pauseNode);
    this->Pause = pauseNode;
     */
    
    auto label1 = Label::createWithSystemFont("剩余僵尸：", "Arial", 40);
    label1->setPosition(800, 750);
    this->addChild(label1, 1);
    
    auto numslabel = Label::createWithSystemFont(to_string(this->remainingZombies), "Arial", 50);
    numslabel->setPosition(920, 750);
    numslabel->setColor(Color3B::RED);
    this->addChild(numslabel, 1);
    this->remainingZombiesNum = numslabel;
    
    auto resumeItem = MenuItemLabel::create(
                                           Label::createWithSystemFont("返回主菜单", "Arial", 40),
                                            [&](Ref* sender){
                                                Director::getInstance()->replaceScene(StartScene::createScene());
                                            });
    resumeItem->setColor(Color3B::BLUE);
    resumeItem->setPosition(1140, 750);
    auto menu = Menu::create(resumeItem , NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    //设置定时器
    this->scheduleUpdate();
    return true;
}


void GameScene::menuCloseCallback(Ref* pSender)
{
    //Director::getInstance()->end();
    Director::getInstance()->replaceScene(VictoryScene::create());
}

//结束时关闭音乐
void GameScene::onExit()
{
    //super
    Scene::onExit();
    this->unscheduleUpdate();
    AudioEngine::stop(this->backgroundAudioID);
}
