#ifndef __NORMALZOMBIE_H__
#define __NORMALZOMBIE_H__

#include"Zombie.h"
class NormalZombie : public Zombie
{
protected:
    virtual void ExamineToChangeTexture();
    virtual bool DoSelfTask(std::vector<Line*>);
public:
    NormalZombie(int,cocos2d::Sprite*);
    ~NormalZombie();
};

#endif
