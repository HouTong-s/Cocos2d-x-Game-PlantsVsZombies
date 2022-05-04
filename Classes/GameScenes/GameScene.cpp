#include "GameScene.h"
#include "../Plants/AllPlants.h"
#include "../VictoryScene.h"
#include "../DefeatScene.h"
#include "../StartScene.h"
#include "../PauseScene.h"
#include "../ZombiesGenerator/FirstGenerator.h"
#include "AudioEngine.h"
USING_NS_CC;
using namespace std;

//getBoundingBox获取节点在父坐标系的矩形框坐标

Scene* GameScene::createScene(int num)
{
    auto scene = GameScene::create();
    scene->TotalZombies = scene->remainingZombies = scene->ZombiesToGenerate = num;
    return scene;
}

void GameScene::HandlePos(float x,float y)
{
    if(this->Shovel->getBoundingBox().containsPoint(Vec2(x, y)))
    {
        this->whichCard = -10;
        return;
    }
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
            if(this->Lawns[i][j]->getBoundingBox().containsPoint(Vec2(x, y)))
            {
                //this->whichCard = -1;
                return;
            }
        }
    for(auto i=0;i<this->AllCards.size();i++)
    {
        if(this->AllCards[i]->getBoundingBox().containsPoint(Vec2(x, y)))
        {
            if(TotalOfSun >= Plant::CardCost[i] && this->isCardsReady[i])
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
    MyRect result;
    for(int i=0;i<this->Row;i++)
        for(int j=0;j<this->Column;j++)
        {
            if(this->Lawns[i][j]->getBoundingBox().containsPoint(Vec2(x, y)))
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
    if(this->whichCard >=0)
    {
        for(int i=0;i<this->allLines[row]->plants.size();i++)
        {
            if(this->allLines[row]->plants[i]->column == col)
            {
                this->whichCard = -1;
                return;
            }
        }
        //种植完之后卡片进入冷却,冷却完毕后更新冷却状态
        this->isCardsReady[whichCard] = false;
        int temp = this->whichCard;
        this->CoolBars[whichCard]->runAction(Sequence::create(ProgressFromTo::create(Plant::CoolTimes                                                   [whichCard], 100, 0),
                                                      CallFunc::create([&,temp](){
                                                        this->isCardsReady[temp] = true;
                                                  }),
                                                  NULL));
        
        this->Lawns[row][col]->setTexture(Plant::PlantsImgs[this->whichCard]);
        Plant* plant;
        switch (this->whichCard)
        {
            case 0:
                plant = new SunFlower(row, col, this->Lawns[row][col],this);
                break;
            case 1:
                plant = new PeaShooter(row, col, this->Lawns[row][col],this);
                break;
            case 2:
                plant = new IceShooter(row, col, this->Lawns[row][col],this);
                break;
            case 3:
                plant = new Nut(row, col, this->Lawns[row][col],this);
                break;
            case 4:
                plant = new PotatoMine(row, col, this->Lawns[row][col],this);
                break;
            case 5:
                plant = new DoubleShooter(row, col, this->Lawns[row][col],this);
                break;
            default:
                break;
        }
        if(plant!= nullptr)
        {
            this->Lawns[row][col]->setContentSize(Size(Lawn_Width, Lawn_Height));
            this->TotalOfSun -= Plant::CardCost[this->whichCard];
            this->allLines[row]->plants.push_back(plant);
        }
    }
    else if(this->whichCard == -10)
    {
        this->Lawns[row][col]->setTexture("草地块.png");
        this->Lawns[row][col]->setContentSize(Size(Lawn_Width, Lawn_Height));
        for(int i=0;i<this->allLines[row]->plants.size();i++)
        {
            if(this->allLines[row]->plants[i]->column == col)
            {
                this->allLines[row]->plants[i]->plantnode->stopAllActions();
                delete this->allLines[row]->plants[i];
                this->allLines[row]->plants.erase(this->allLines[row]->plants.begin()+i);
            }
        }
    }
    this->whichCard = -1;
}

void GameScene::touchSun(float x,float y)
{
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

void GameScene::onContactDown(float x,float y)
{
    touchSun(x, y);
    HandlePos(x, y);
}

void GameScene::onContactUp(float x,float y)
{
    MyRect rect = PosToPlant(x, y);
    if(rect.isLawn == true)
    {
        PlantPlants(rect.row, rect.column);
    }
}

void GameScene::onContactMove(float x,float y)
{
    touchSun(x, y);
}

void GameScene::GenerateFlowerSunShape(float x,float y)
{
    Sprite* sunNode = Sprite::create("阳光.png");
    this->SunShapes.pushBack(sunNode);
    sunNode->setPosition(x,y);
    sunNode->setContentSize(Size(75, 75));
    this->addChild(sunNode,100);
    sunNode->runAction(MoveBy::create(4, Vec2(0, -100)));
}

void GameScene::GenerateAutomaticSunShape()
{
    Sprite* sunNode = Sprite::create("阳光.png");
    int x,y;
    x = rand()%Lawn_Left + Lawn_Left+30;
    y = rand()%(Lawn_Top/2) - Lawn_Top;
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
            if(!(*j)->execute())
            {
                (*j)->plantnode->stopAllActions();
                (*j)->plantnode->setTexture("草地块.png");
                (*j)->plantnode->setContentSize(Size(Lawn_Width, Lawn_Height));
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
        if(!(*i)->execute())
        {
            (*i)->propnode->removeFromParent();
            delete *i;
            i = this->allProps.erase(i);
        }
        else
        {
            i++;
        }
    }
}

void GameScene::HandlePause()
{
    this->zombiesgenerator->Start += this->pauseTime;
    this->hasPaused = false;
}

void GameScene::JudgeIsFailed()
{
    for(int i=0;i<this->Row;i++)
        for(auto j=this->allLines[i]->zombies.begin();j!=this->allLines[i]->zombies.end();j++)
        {
            if((*j)->zombienode != nullptr && (*j)->zombienode->getPosition().x < Lawn_Left - 30)
            {
                Director::getInstance()->replaceScene(DefeatScene::create());
                break;
            }
        }
}

void GameScene::update(float dt)
{
    for(auto i=0;i<this->AllCards.size();i++)
    {
        if(this->TotalOfSun >= Plant::CardCost[i] && this->isCardsReady[i])
        {
            AllCards[i]->setColor(Color3B::WHITE);
            //AllCards[i]->setOpacity(255);
        }
        else
        {
            AllCards[i]->setColor(Color3B(150,150,150));
            //AllCards[i]->setOpacity(200);
        }
    }
    //判断胜利条件
    if(this->remainingZombies <= 0)
    {
        Director::getInstance()->replaceScene(VictoryScene::create());
    }
    //判断失败条件
    JudgeIsFailed();
    // 处理暂停
    if(this->hasPaused)
    {
        HandlePause();
    }
    //常规的更新操作
    this->SunNumNode->setString(to_string(this->TotalOfSun));
    this->remainingZombiesNum->setString(to_string(this->remainingZombies));
    executeAll();
    //以下生成僵尸
    this->zombiesgenerator->execute(this);
}

bool GameScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    //初始化数据
    this->zombiesgenerator = new FirstGenerator();
    for(int i=0;i<this->Row;i++)
    {
        this->allLines.push_back(new Line());
    }
    this->Lawns.resize(this->Row,vector<Sprite*>(this->Column,nullptr));
    //重置随机数
    srand(time(0));
    //初始化生成阳光的action
    this->runAction(RepeatForever::create(Sequence::create(
        DelayTime::create(4),
        CallFunc::create([&](){
            this->GenerateAutomaticSunShape();
        }),
        NULL
    )));
    
    //注册鼠标事件（PC）或者触摸事件（手机）
#ifdef CC_PLATFORM_PC
    auto _mouseListener = EventListenerMouse::create();
    _mouseListener->onMouseMove = [this](EventMouse* event){
        if(event->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT)
        {
            this->onContactMove(event->getCursorX(),event->getCursorY());
        }
    };
    _mouseListener->onMouseUp = [this](EventMouse* event){
        if(event->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT)
        {
            this->onContactUp(event->getCursorX(),event->getCursorY());
        }
    };
    _mouseListener->onMouseDown = [this](EventMouse* event){
        if(event->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT)
        {
            this->onContactDown(event->getCursorX(),event->getCursorY());
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
#else
    auto _touchListener = EventListenerTouchOneByOne::create();
    _touchListener->onTouchBegan = [this](Touch* touch, Event* event){
        Vec2 vec2 =  touch->getLocation();
        this->onContactDown(vec2.x,vec2.y);
        return true;
    };
    _touchListener->onTouchMoved = [this](Touch* touch, Event* event){
        Vec2 vec2 =  touch->getLocation();
        this->onContactMove(vec2.x,vec2.y);
    };
    _touchListener->onTouchEnded = [this](Touch* touch, Event* event){
        Vec2 vec2 =  touch->getLocation();
        this->onContactUp(vec2.x,vec2.y);
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
#endif
    //播放背景音乐
    this->backgroundAudioID = AudioEngine::play2d("music/BackGroundMusic.mp3", true);
    //AudioEngine::setVolume(this->backgroundAudioID, 0);
    //获取窗口大小
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // 添加背景图片
    auto sprite = Sprite::create("背景.png");
    sprite->setContentSize(Size(ScreenWidth, ScreenHeight));
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);
    //添加卡片
    for(int i=0;i<Plant::CardImgs.size();i++)
    {
        auto cardTemp = Sprite::create(Plant::CardImgs[i]);
        cardTemp->setPosition(265, 684-i*100);
        //cardTemp->setContentSize(Size(189, 116));
        this->AllCards.push_back(cardTemp);
        this->addChild(cardTemp);
        //以下操作用来初始化冷却条,并且除了向日葵以外的植物最开始都尚未冷却好
        auto barSprite = Sprite::create(Plant::CardImgs[i]);
        auto coolBarTemp = ProgressTimer::create(barSprite);
        //R=G=B时为灰色，且值越小越深
        coolBarTemp->setColor(Color3B(90,90,90));
        coolBarTemp->setMidpoint(Vec2(1, 0.5));
        coolBarTemp->setBarChangeRate(Vec2(1, 0));
        coolBarTemp->setType(ProgressTimer::Type::BAR);
        coolBarTemp->setPosition(265, 684-i*100);
        if(i>0)
        {
            coolBarTemp->runAction(Sequence::create(ProgressFromTo::create(Plant::CoolTimes                                                   [i], 100, 0),
                                                          CallFunc::create([&,i](){
                                                            this->isCardsReady[i] = true;
                                                      }),
                                                      NULL));
        }
        //coolBarTemp->setContentSize(Size(189, 116));
        this->CoolBars.push_back(coolBarTemp);
        this->addChild(coolBarTemp);
    }
    //添加草地块
    for(int i=0;i<5;i++)
        for(int j=0;j<9;j++)
        {
            auto plantTemp = Sprite::create("草地块.png");
            plantTemp->setPosition(Lawn_Left+Lawn_Width*j, Lawn_Top-Lawn_Height*i);
            plantTemp->setAnchorPoint(Vec2(0, 1));
            plantTemp->setContentSize(Size(Lawn_Width, Lawn_Height));
            this->Lawns[i][j] = plantTemp;
            this->addChild(plantTemp);
        }
    //添加阳光值
    auto SunCard = Sprite::create("阳光1.png");
    SunCard->setPosition(95, 624);
    SunCard->setContentSize(Size(110, 110));
    this->addChild(SunCard);
    //以下是一个黑色的背景，用于显示阳光值
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
    //铲子
    auto shovelNode = Sprite::create("铲子.png");
    shovelNode->setPosition(60, 60);
    shovelNode->setContentSize(Size(90, 90));
    this->addChild(shovelNode);
    this->Shovel = shovelNode;
    //暂停键
    auto pauseItem = MenuItemImage::create("暂停.png", "暂停.png",
       [&](Ref* sender){
        auto visibleSize = Director::getInstance()->getVisibleSize();
        RenderTexture* renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);
        renderTexture->begin();
        this->visit();
        renderTexture->end();
        this->pauseStart = chrono::system_clock::now();
        //这个时候要调用onExit了，但是不是销毁
        this->isDestroy = false;
        Director::getInstance()->pushScene(PauseScene::createScene(renderTexture));
    });
    pauseItem->setPosition(1300, 750);
    //显示剩余僵尸
    auto label1 = Label::createWithSystemFont("剩余僵尸：", "Arial", 40);
    label1->setPosition(750, 750);
    this->addChild(label1, 1);
    
    auto numslabel = Label::createWithSystemFont(to_string(this->remainingZombies), "Arial", 50);
    numslabel->setPosition(870, 750);
    numslabel->setColor(Color3B::RED);
    this->addChild(numslabel, 1);
    this->remainingZombiesNum = numslabel;
    //返回主菜单按钮
    auto resumeItem = MenuItemLabel::create(
                                           Label::createWithSystemFont("返回主菜单", "Arial", 40),
                                            [&](Ref* sender){
                                                Director::getInstance()->replaceScene(StartScene::createScene());
                                            });
    resumeItem->setColor(Color3B::BLUE);
    resumeItem->setPosition(1080, 750);
    auto menu = Menu::create(resumeItem ,pauseItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    //设置定时器
    this->scheduleUpdate();
    return true;
}

void GameScene::onExit()
{
    Scene::onExit();
    this->unscheduleUpdate();
    //销毁场景时直接停止音乐，否则只是暂停
    if(this->isDestroy)
    {
        AudioEngine::stop(this->backgroundAudioID);
    }
    else
    {
        AudioEngine::pause(this->backgroundAudioID);
        this->isDestroy = true;
    }
}

void GameScene::onEnter()
{
    Scene::onEnter();
    //不是初始化的时候调用以下代码
    if(!this->initing)
    {
        this->scheduleUpdate();
        this->hasPaused = true;
        auto end = chrono::system_clock::now();
        //记录暂停的间隔
        this->pauseTime = chrono::duration_cast<chrono::milliseconds>(end - this->pauseStart);
        CCLOG("%lld",this->pauseTime.count());
        AudioEngine::resume(this->backgroundAudioID);
    }
    //初始化之后就把变量initing设为false，之后暂停的时候就会执行上方if内的代码
    else
    {
        this->initing = false;
    }
}

GameScene::~GameScene()
{
    delete this->zombiesgenerator;
    for(auto i = this->allProps.begin();i!= this->allProps.end();i++)
    {
        delete *i;
    }
    for(auto i=0;i<this->Row;i++)
    {
        for(auto j = this->allLines[i]->plants.begin(); j != this->allLines[i]->plants.end(); j++)
        {
            delete *j;
        }
        for(auto k = this->allLines[i]->zombies.begin(); k != this->allLines[i]->zombies.end(); k++)
        {
            delete *k;
        }
        delete this->allLines[i];
    }
}
