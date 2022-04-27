#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__
#include"cocos2d.h"
#include <chrono>
#include"../Board/DataStructures.h"
#include<string>
#include<vector>
class Zombie
{
private:
    int row;
    std::chrono::system_clock::time_point EatStart;
    float speed=20;
protected:
    bool IsAlive();
    virtual void ExamineToChangeTexture()=0;
public:
    int lifeValue;
    std::chrono::system_clock::time_point SlowStart;
    bool isSlowed = false;
    bool slowWalking = false;
    bool hasAction = true;
    int slowtime = 0;
    cocos2d::Sprite* zombienode;
    Zombie(int,cocos2d::Sprite*);
    virtual ~Zombie();
    bool move(std::vector<Line*>);
};

#endif
