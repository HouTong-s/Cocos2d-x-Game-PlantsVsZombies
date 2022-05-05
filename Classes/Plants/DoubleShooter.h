#ifndef __DOUBLESHOOTER_H__
#define __DOUBLESHOOTER_H__

#include"cocos2d.h"
#include"Plant.h"
class DoubleShooter : public Plant
{
private:
    bool isSecend = false;
protected:
    virtual bool DoSelfTask();

    //是否正在射击
    bool isShooting = false;
public:
    DoubleShooter(int , int ,cocos2d::Sprite*,GameScene*);
    ~DoubleShooter();
};

#endif
