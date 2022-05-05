#include "SunFlower.h"
#include "../GameScenes/GameScene.h"
#include "../Board/DataStructures.h"
#include"../Zombies/Zombie.h"
//#include <stdlib.h>
#include <time.h>
using namespace std;
using namespace cocos2d;
SunFlower::SunFlower(int row,int col,Sprite* node,GameScene* scene):Plant(row,col,node,scene)
{
    this->plantnode->runAction(RepeatForever::create(Sequence::create(
        DelayTime::create(10),
        CallFunc::create([&](){
            Vec2 positon = this->plantnode->getPosition();
            this->scene->GenerateFlowerSunShape(positon.x + 30 + rand() % 40, positon.y - 20);
        }),
        NULL
    )));
}

SunFlower::~SunFlower()
{
}
bool SunFlower::DoSelfTask()
{
    if(this->plantnode != nullptr)
    {
        return true;
    }
    return false;
}

