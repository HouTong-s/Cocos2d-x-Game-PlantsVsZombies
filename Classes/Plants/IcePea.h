#ifndef __ICEPEA_H__
#define __ICEPEA_H__

#include"cocos2d.h"
#include"Plant.h"
class IcePea : public Plant
{
private:
    int speed;
protected:
    virtual bool DoSelfTask(GameScene* scene);
public:
    IcePea(int , int ,cocos2d::Sprite*);
    ~IcePea();
};

#endif
