#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include"cocos2d.h"
#include"../Board/DataStructures.h"
#include<string>
#include<vector>
class Zombie
{
protected:
    static const int moveTag;
    static const int eatTag;
    static const int slowTag;
    int row;
    float speed=22;
    
    //检查生命的函数
    bool IsAlive();
    
    //检查当前的生命值，是否该更换图片
    virtual void ExamineToChangeTexture()=0;
    
    //由子类来扩写的函数，执行自身特有的行动
    virtual bool DoSelfTask(std::vector<Line*>)=0;
public:
    int lifeValue = 10;
    bool isSlowed = false;
    bool slowWalking = false;
    bool isWalking = true;
    bool isEating = false;
    bool slowEating = false;
    bool isSlowEating = false;
    int slowtime = 0;
    cocos2d::Sprite* zombienode;
    Zombie(int,cocos2d::Sprite*);
    virtual ~Zombie();

    //被施加减速
    void putSlow(int);

    //每一帧都调用，返回false说明僵尸对象将要被销毁
    virtual bool move(std::vector<Line*>);
};

#endif
