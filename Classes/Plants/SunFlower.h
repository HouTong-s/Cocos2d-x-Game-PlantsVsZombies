#ifndef __SUNFLOWER_H__
#define __SUNFLOWER_H__

#include"cocos2d.h"
#include"Plant.h"
class SunFlower : public Plant
{
protected:
    virtual bool DoSelfTask();
public:
    SunFlower(int , int ,cocos2d::Sprite*,GameScene*);
    ~SunFlower();
};

#endif
