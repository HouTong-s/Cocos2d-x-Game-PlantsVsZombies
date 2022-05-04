#ifndef __PROP_H__
#define __PROP_H__

#include"cocos2d.h"
#include<string>

class GameScene;
class Prop
{
public:
    int row;
    int speed;
    cocos2d::Sprite* propnode;
    GameScene* scene;
    Prop(int,cocos2d::Sprite*,GameScene*);
    virtual ~Prop();
    virtual bool execute()=0;
};

#endif
