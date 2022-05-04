#ifndef __PEA_H__
#define __PEA_H__

#include"cocos2d.h"
#include"Prop.h"
class Pea : public Prop
{
public:
    Pea(int , cocos2d::Sprite*,GameScene*);
    ~Pea();
    virtual bool execute();
};

#endif
