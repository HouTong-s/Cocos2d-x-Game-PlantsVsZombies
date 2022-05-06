#ifndef __GameScene_H__
#define __GameScene_H__

#include "cocos2d.h"
#include "../Plants/Plant.h"
#include "../Props/Prop.h"
#include "../Zombies/Zombie.h"
#include "../ZombiesGenerator/AbstarctGenerator.h"
#include <vector>
#include "../Board/DataStructures.h"
#include <string>
#include <chrono>
class GameScene : public cocos2d::Scene
{
private:
    //自动产生阳光
    void GenerateAutomaticSunShape();
    
    //PC：按下鼠标；手机：按下触摸
    void onContactDown(float,float);
    
    //PC：鼠标放起；手机：触摸结束
    void onContactUp(float,float);
    
    //PC：鼠标移动；手机：触摸移动
    void onContactMove(float,float);
    
    //判断坐标（x,y）是否捡到了阳光
    void touchSun(float x,float y);
    
    //判断坐标（x,y）是否点到了卡片或者铲子，会改变whichCard的值
    void HandlePos(float x,float y);
    
    //判断坐标（x,y）是否点到了草地块
    MyRect PosToPlant(float x,float y);
    
    //种植植物
    void PlantPlants(int row,int col);
    
    //暂停过后，所有时间相关的都延后暂停的时间间隔
    void HandlePause();
    
    //执行所有植物、僵尸、道具的更新
    void executeAll();
    
    //判断失败条件
    void JudgeIsFailed();
    
    CREATE_FUNC(GameScene);
    
public:
    //僵尸生成器
    AbstarctGenerator* zombiesgenerator;
    
    int backgroundAudioID;
    int count = 0;
    bool initing = true;
    bool isDestroy = true;
    bool hasPaused = false;
    std::chrono::system_clock::time_point pauseStart;
    std::chrono::milliseconds pauseTime;
    int TotalZombies;
    int ZombiesToGenerate;
    int remainingZombies;
    
    //阳光值，初始为50
    int TotalOfSun = 50;
    
    int Row = 5;
    int Column = 9;
    
    //whichCard为-10表示铲子，为正表示选中了卡片，为-1则无效
    int whichCard =-1;
    
    //显示阳光数值的标签
    cocos2d::Label* SunNumNode;
    
    //剩余的僵尸数量
    cocos2d::Label* remainingZombiesNum;
    
    //铲子
    cocos2d::Sprite* Shovel;
    
    //所有的草地块
    std::vector<std::vector<cocos2d::Sprite*>> Lawns;
    
    //所有的卡片
    std::vector<cocos2d::Sprite*> AllCards;
    
    //所有的道具，比如豌豆
    std::vector<Prop*> allProps;
    
    //五条线
    std::vector<Line*> allLines;
    
    //冷却条ui
    std::vector<cocos2d::ProgressTimer*> CoolBars;
    
    //植物卡片是否已经准备好
    bool isCardsReady[6] = {true,false,false,false,false,false};
    
    //所有阳光
    std::vector<cocos2d::Sprite*> SunShapes;
    
    static cocos2d::Scene* createScene(std::string str,int num = 50);
    void GenerateFlowerSunShape(float,float);
    virtual bool init() override;
    void update(float dt) override;
    

    //析构函数，释放所有的plant、zombie、prop对象
    ~GameScene();
    
    //结束或暂停时时关闭音乐
    void onExit() override;
    
    //暂停结束后，记录时间间隔
    void onEnter() override;
};

#endif
