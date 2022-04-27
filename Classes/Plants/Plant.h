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
    std::chrono::system_clock::time_point start;
    bool IsAlive();
    virtual bool DoSelfTask(GameScene* scene)=0;
public:
    int row;
    int column;
    static std::vector<std::string>  PlantsNames;
    static int CardCost[];
    static std::vector<std::string> CardImgs;
    static std::vector<std::string> PlantsImgs;
    cocos2d::Sprite* plantnode;
    int lifeValue = 4;
    Plant(int,int,cocos2d::Sprite*);
    virtual ~Plant();
    bool execute(GameScene* scene);
};


#endif
