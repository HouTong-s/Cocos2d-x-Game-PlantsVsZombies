//
//  GameScene.hpp
//  PlantsVsZombies
//
//  Created by houtong on 2022/4/24.
//
#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__
#include "cocos2d.h"
#include "Plants/Plant.h"
#include "Zombies/Zombie.h"
#include "ZombiesGenerator/AllGenerators.h"
#include <vector>
#include "Board/DataStructures.h"
#include <chrono>
class GameScene : public cocos2d::Scene
{
private:
    void GenerateAutomaticSunShape();
    void onMouseDown(cocos2d::Event *);
    void onMouseUp(cocos2d::Event *);
    void onMouseMove(cocos2d::Event *);
    void touchSun(float x,float y);
    void HandlePos(float x,float y);
    MyRect PosToPlant(float x,float y);
    void PlantPlants(int row,int col);
    bool Vec2Contains();
    void executeAll();
    void JudgeIsFailed();
public:
    FirstGenerator zombiesgenerator;
    int backgroundAudioID;
    int count = 0;
    std::chrono::system_clock::time_point start;
    int TotalZombies;
    int ZombiesToGenerate;
    int remainingZombies;
    int TotalOfSun = 300;
    int Row = 5;
    int Column = 9;
    //whichCard为-10表示暂停，为正表示选中了卡片，为-1则无效
    int whichCard =-1;
    cocos2d::Label* SunNumNode;
    cocos2d::Label* remainingZombiesNum;
    cocos2d::Sprite* Shovel;
    cocos2d::Sprite* Pause;
    std::vector<std::vector<cocos2d::Sprite*>> AllPieces;
    std::vector<cocos2d::Sprite*> AllCards;
    std::vector<Plant*> allProps;
    std::vector<Line*> allLines;
    cocos2d::Vector<cocos2d::Sprite*> SunShapes;
    static cocos2d::Scene* createScene(int num = 50);
    void GenerateFlowerSunShape(float,float);
    
    virtual bool init() override;
    void update(float dt) override;
    void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(GameScene);
    void onExit() override;
};

#endif /* GameScene_hpp */
