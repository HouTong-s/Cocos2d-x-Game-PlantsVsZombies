#include "PotatoMine.h"
#include "../GameScene.h"
#include "../Board/DataStructures.h"
#include"../Zombies/Zombie.h"
#include"stdlib.h"
#include"math.h"
using namespace cocos2d;
using namespace std;
PotatoMine::PotatoMine(int row,int col,Sprite* node):Plant(row,col,node)
{
    this->lifeValue = 10;
}

PotatoMine::~PotatoMine()
{
}
bool PotatoMine::DoSelfTask(GameScene* scene)
{
    if(this->plantnode != nullptr)
    {
        if(this->isReady == false)
        {
            auto end = chrono::system_clock::now();
            chrono::duration<double> diff = end - this->start;
            if(abs(10- diff.count()) <0.01)
            {
                this->isReady = true;
                this->plantnode->setTexture("土豆地雷2.png");
            }
        }
        else
        {
            bool isBoom = false;
            for(auto i=scene->allLines[this->row]->zombies.begin();i!=scene->allLines[this->row]->zombies.end();i++)
            {
                Rect rect = this->plantnode->getBoundingBox();
                if(rect.containsPoint((*i)->zombienode->getPosition()))
                {
                    (*i)->lifeValue = 0;
                    Rect newRect;
                    newRect.setRect(rect.origin.x-10, rect.origin.y, rect.size.width+50, rect.size.height);
                    for(auto j=scene->allLines[this->row]->zombies.begin();j!=scene->allLines[this->row]->zombies.end();j++)
                    {
                        if(newRect.containsPoint((*j)->zombienode->getPosition()))
                        {
                            (*j)->lifeValue = 0;
                        }
                    }
                    isBoom = true;
                    break;
                }
            }
            if(isBoom)
            {
                this->lifeValue = 0;
            }
        }
        return true;
    }
    return false;
}

