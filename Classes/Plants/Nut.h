#ifndef __NUT_H__
#define __NUT_H__

#include"cocos2d.h"
#include"Plant.h"
class Nut : public Plant
{
protected:
    virtual bool DoSelfTask(GameScene* scene);
public:
    Nut(int , int ,cocos2d::Sprite*);
    ~Nut();
};

#endif
