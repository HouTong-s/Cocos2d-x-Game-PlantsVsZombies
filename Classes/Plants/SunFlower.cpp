#include "SunFlower.h"
#include "../GameScene.h"
#include "../Board/DataStructures.h"
#include"../Zombies/Zombie.h"
//#include <stdlib.h>
#include <time.h>
using namespace std;
using namespace cocos2d;
SunFlower::SunFlower(int row,int col,Sprite* node):Plant(row,col,node)
{
}

SunFlower::~SunFlower()
{
}
bool SunFlower::DoSelfTask(GameScene* scene)
{
    if(this->plantnode != nullptr)
    {
        auto end = chrono::system_clock::now();
        chrono::duration<double> diff = end - this->start;
        if(diff.count() > 9.99  )
        {
            this->start = end;
            Vec2 positon = this->plantnode->getPosition();
            srand(time(NULL));
            scene->GenerateFlowerSunShape(positon.x + 30 + rand() % 40, positon.y - 20);
        }
        return true;
    }
    return false;
}

