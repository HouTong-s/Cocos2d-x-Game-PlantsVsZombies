#ifndef __CONEHEADZOMBIE_H__
#define __CONEHEADZOMBIE_H__
#include"Zombie.h"
class ConeHeadZombie : public Zombie
{
protected:
    virtual void ExamineToChangeTexture();
public:
    ConeHeadZombie(int,cocos2d::Sprite*);
    ~ConeHeadZombie();
};



#endif
