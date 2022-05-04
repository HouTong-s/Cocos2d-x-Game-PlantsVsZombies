#include "Pea.h"
#include "../GameScenes/GameScene.h"
#include "../Board/DataStructures.h"
#include"../Zombies/Zombie.h"
using namespace cocos2d;
Pea::Pea(int row,Sprite* node,GameScene* scene):Prop(row,node,scene)
{
    this->speed = 240;
    Vec2 rect = node->getPosition();
    node->setContentSize(Size(30, 30));
    node->runAction(MoveTo::create(float((ScreenWidth+10-rect.x)/this->speed), Vec2(ScreenWidth+10, rect.y)));
}

Pea::~Pea()
{
}
bool Pea::execute()
{
    if(this->propnode != nullptr)
    {
        for(auto i=scene->allLines[this->row]->zombies.begin();i!=scene->allLines[this->row]->zombies.end();i++)
        {
            if((*i)->zombienode->getBoundingBox().containsPoint(this->propnode->getPosition()))
            {
                (*i)->lifeValue -=1;
                return false;
            }
        }
        if(this->propnode->getPosition().x >= ScreenWidth+10)
        {
            return false;
        }
        return true;
    }
    return false;
}
