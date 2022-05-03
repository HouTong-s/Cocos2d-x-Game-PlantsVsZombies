#ifndef __BUCKETZOMBIE_H__
#define __BUCKETZOMBIE_H__

#include"NormalZombie.h"
class BucketZombie : public NormalZombie
{
protected:
    virtual void ExamineToChangeTexture();
public:
    BucketZombie(int,cocos2d::Sprite*);
    ~BucketZombie();
};

#endif
