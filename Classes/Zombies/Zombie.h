#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include"cocos2d.h"
#include <chrono>
#include"../Board/DataStructures.h"
#include<string>
#include<vector>
class Zombie
{
protected:
    int row;
    float speed=20;
    bool IsAlive();
    virtual void ExamineToChangeTexture()=0;
    virtual bool DoSelfTask(std::vector<Line*>)=0;
public:
    int lifeValue;
    std::chrono::system_clock::time_point EatStart;
    std::chrono::system_clock::time_point SlowStart;
    bool isSlowed = false;
    bool slowWalking = false;
    bool hasAction = true;
    int slowtime = 0;
    cocos2d::Sprite* zombienode;
    Zombie(int,cocos2d::Sprite*);
    virtual ~Zombie();
    virtual bool move(std::vector<Line*>);
};

#endif
