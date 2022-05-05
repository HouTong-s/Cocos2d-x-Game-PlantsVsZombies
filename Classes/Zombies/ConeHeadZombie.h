#ifndef __CONEHEADZOMBIE_H__
#define __CONEHEADZOMBIE_H__

#include"NormalZombie.h"
class ConeHeadZombie : public NormalZombie
{
protected:
    virtual void ExamineToChangeTexture();
public:
    ConeHeadZombie(int,cocos2d::Sprite*);
    ~ConeHeadZombie();
};

#endif
