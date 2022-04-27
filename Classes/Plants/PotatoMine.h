#ifndef __POTATOMINE_H__
#define __POTATOMINE_H__
#include"cocos2d.h"
#include"Plant.h"
class PotatoMine : public Plant
{
protected:
    bool isReady = false;
    virtual bool DoSelfTask(GameScene* scene);
public:
    PotatoMine(int , int ,cocos2d::Sprite*);
    ~PotatoMine();
};



#endif
