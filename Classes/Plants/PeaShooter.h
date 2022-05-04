#ifndef __PEASHOOTER_H__
#define __PEASHOOTER_H__

#include"cocos2d.h"
#include"Plant.h"
class PeaShooter : public Plant
{
protected:
    virtual bool DoSelfTask();

    //是否正在射击
    bool isShooting = false;
public:
    PeaShooter(int , int ,cocos2d::Sprite*,GameScene*);
    ~PeaShooter();
};

#endif
