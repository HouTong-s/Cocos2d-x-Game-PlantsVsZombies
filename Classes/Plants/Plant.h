#ifndef __PLANT_H__
#define __PLANT_H__

#include"cocos2d.h"
#include<vector>
#include<string>

class GameScene;
class Plant
{
protected:
    GameScene* scene;
    
    //检查生命的函数
    bool IsAlive();
    
    //由子类来扩写的函数，执行自身特有的行动
    virtual bool DoSelfTask()=0;
public:
    static const std::vector<std::string>  PlantsNames;
    static const std::vector<int> CardCost;
    static const std::vector<std::string> CardImgs;
    static const std::vector<std::string> PlantsImgs;
    static const std::vector<int> CoolTimes;

    int row;
    int column;
    cocos2d::Sprite* plantnode;
    int lifeValue = 4;
    Plant(int,int,cocos2d::Sprite*,GameScene* );
    virtual ~Plant();
    
    //每一帧都调用的函数，返回false时，说明植物应当被销毁
    bool execute();
};

#endif
