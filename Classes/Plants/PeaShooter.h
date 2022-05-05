#ifndef __PEASHOOTER_H__
#define __PEASHOOTER_H__

#include"cocos2d.h"
#include"Plant.h"
class PeaShooter : public Plant
{
protected:
    virtual bool DoSelfTask(GameScene* scene);
public:
    PeaShooter(int , int ,cocos2d::Sprite*);
    ~PeaShooter();
};

#endif
