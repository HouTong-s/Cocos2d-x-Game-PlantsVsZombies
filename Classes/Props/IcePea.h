#ifndef __ICEPEA_H__
#define __ICEPEA_H__

#include"cocos2d.h"
#include"Prop.h"
class IcePea : public Prop
{
public:
    IcePea(int ,cocos2d::Sprite*,GameScene*);
    ~IcePea();
    virtual bool execute();
};

#endif
