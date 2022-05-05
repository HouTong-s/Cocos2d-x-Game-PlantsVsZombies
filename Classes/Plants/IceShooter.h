#ifndef __ICESHOOTER_H__
#define __ICESHOOTER_H__

#include"cocos2d.h"
#include"Plant.h"
class IceShooter : public Plant
{
protected:
    virtual bool DoSelfTask();

    //是否正在射击
    bool isShooting = false;
public:
    IceShooter(int , int ,cocos2d::Sprite*,GameScene*);
    ~IceShooter();
};

#endif
