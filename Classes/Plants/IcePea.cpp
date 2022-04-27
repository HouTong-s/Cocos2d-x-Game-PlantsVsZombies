#include "IcePea.h"
#include "../GameScene.h"
#include "../Board/DataStructures.h"
#include"../Zombies/Zombie.h"
using namespace cocos2d;
using namespace std;
IcePea::IcePea(int row,int col,Sprite* node):Plant(row,col,node)
{
    this->speed = 240;
    Vec2 rect = node->getPosition();
    node->setContentSize(Size(30, 30));
    node->runAction(MoveTo::create(float((1430-rect.x)/this->speed), Vec2(1430, rect.y)));
}

IcePea::~IcePea()
{
}
bool IcePea::DoSelfTask(GameScene* scene)
{
    if(this->plantnode != nullptr)
    {
        for(auto i=scene->allLines[this->row]->zombies.begin();i!=scene->allLines[this->row]->zombies.end();i++)
        {
            if((*i)->zombienode->getBoundingBox().containsPoint(this->plantnode->getPosition()))
            {
                (*i)->lifeValue -=1;
                (*i)->SlowStart = chrono::system_clock::now();
                (*i)->slowtime = 8;
                if((*i)->isSlowed == false)
                {
                    (*i)->isSlowed = true;
                }
                this->lifeValue = 0;
                this->plantnode->removeFromParent();
                return false;
            }
        }
        if(this->plantnode->getPosition().x >= 1430)
        {
            this->plantnode->stopAllActions();
            this->plantnode->removeFromParent();
            return false;
        }
        return true;
    }
    return false;
}
