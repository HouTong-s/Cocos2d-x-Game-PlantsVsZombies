#include "Nut.h"
#include "../GameScene.h"
#include "../Board/DataStructures.h"
#include"../Zombies/Zombie.h"
using namespace cocos2d;
Nut::Nut(int row,int col,Sprite* node):Plant(row,col,node)
{
    this->lifeValue = 50;
}

Nut::~Nut()
{
}
bool Nut::DoSelfTask(GameScene* scene)
{
    return true;
}


