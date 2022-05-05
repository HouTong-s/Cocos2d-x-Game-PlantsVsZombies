#ifndef __PLANT_H__
#define __PLANT_H__

#include"cocos2d.h"
#include<vector>
#include<string>
#include<chrono>

class GameScene;
class Plant
{
protected:
    bool IsAlive();
    virtual bool DoSelfTask(GameScene* scene)=0;
public:
    int row;
    int column;
    std::chrono::system_clock::time_point start;
    static const std::vector<std::string>  PlantsNames;
    static const std::vector<int> CardCost;
    static const std::vector<std::string> CardImgs;
    static const std::vector<std::string> PlantsImgs;
    static const std::vector<int> CoolTimes;
    cocos2d::Sprite* plantnode;
    int lifeValue = 4;
    Plant(int,int,cocos2d::Sprite*);
    virtual ~Plant();
    bool execute(GameScene* scene);
};

#endif
