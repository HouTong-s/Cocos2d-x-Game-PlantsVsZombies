#ifndef __SUNFLOWER_H__
#define __SUNFLOWER_H__
#include"cocos2d.h"
#include"Plant.h"
class SunFlower : public Plant
{
private:
    int speed = 20;
protected:
    virtual bool DoSelfTask(GameScene* scene);
public:
    SunFlower(int , int ,cocos2d::Sprite*);
    ~SunFlower();
};


#endif
