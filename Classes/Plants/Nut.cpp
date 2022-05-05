#include "Nut.h"
#include "../GameScenes/GameScene.h"
#include "../Board/DataStructures.h"
#include"../Zombies/Zombie.h"
using namespace cocos2d;
Nut::Nut(int row,int col,Sprite* node,GameScene* scene):Plant(row,col,node,scene)
{
    this->lifeValue = 50;
}

Nut::~Nut()
{
}
bool Nut::DoSelfTask()
{
    if(this->plantnode != nullptr)
    {
        return true;
    }
    return false;
}


