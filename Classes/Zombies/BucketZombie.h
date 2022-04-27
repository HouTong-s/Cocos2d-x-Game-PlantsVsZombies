#ifndef __BUCKETZOMBIE_H__
#define __BUCKETZOMBIE_H__
#include"Zombie.h"
class BucketZombie : public Zombie
{
protected:
    virtual void ExamineToChangeTexture();
public:
    BucketZombie(int,cocos2d::Sprite*);
    ~BucketZombie();
};



#endif
