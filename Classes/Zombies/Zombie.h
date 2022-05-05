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
    bool IsAlive();
    virtual void ExamineToChangeTexture()=0;
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

    //移动
    virtual bool move(std::vector<Line*>);
};

#endif
