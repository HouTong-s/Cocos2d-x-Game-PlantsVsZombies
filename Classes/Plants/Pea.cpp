#include "Pea.h"
#include "../GameScene.h"
#include "../Board/DataStructures.h"
#include"../Zombies/Zombie.h"
using namespace cocos2d;
Pea::Pea(int row,int col,Sprite* node):Plant(row,col,node)
{
    this->speed = 240;
    Vec2 rect = node->getPosition();
    node->setContentSize(Size(30, 30));
    node->runAction(MoveTo::create(float((1430-rect.x)/this->speed), Vec2(1430, rect.y)));
}

Pea::~Pea()
{
}
bool Pea::DoSelfTask(GameScene* scene)
{
    if(this->plantnode != nullptr)
    {
        /*
        Vec2 rect = this->plantnode->getPosition();
        this->plantnode->runAction(MoveTo::create(float((640-rect.x)/this->speed), Vec2(640, rect.y)));
         */
        for(auto i=scene->allLines[this->row]->zombies.begin();i!=scene->allLines[this->row]->zombies.end();i++)
        {
            if((*i)->zombienode->getBoundingBox().containsPoint(this->plantnode->getPosition()))
            {
                (*i)->lifeValue -=1;
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
