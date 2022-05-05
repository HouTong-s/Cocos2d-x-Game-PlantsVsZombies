#ifndef __PEA_H__
#define __PEA_H__

#include"cocos2d.h"
#include"Plant.h"
#include<vector>
class Pea : public Plant
{
private:
    int speed;
protected:
    virtual bool DoSelfTask(GameScene* scene);
public:
    Pea(int , int ,cocos2d::Sprite*);
    ~Pea();
};

#endif
