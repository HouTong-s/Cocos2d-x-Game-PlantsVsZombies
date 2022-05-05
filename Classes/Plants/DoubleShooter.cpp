#include "DoubleShooter.h"
#include "../GameScenes/GameScene.h"
#include "../Board/DataStructures.h"
#include"../Zombies/Zombie.h"
#include "../Props/Pea.h"
using namespace cocos2d;
using namespace std;
DoubleShooter::DoubleShooter(int row,int col,Sprite* node,GameScene* scene):Plant(row,col,node,scene)
{
}

DoubleShooter::~DoubleShooter()
{
}
bool DoubleShooter::DoSelfTask()
{
    if(this->plantnode != nullptr)
    {
        if(this->isSecend)
        {
            Sprite* peaNode = Sprite::create("豌豆.png");
            Vec2 positon = this->plantnode->getPosition();
            peaNode->setPosition(positon.x+100,positon.y-50);
            scene->addChild(peaNode);
            Pea* pea = new Pea(this->row,peaNode,this->scene);
            scene->allProps.push_back(pea);
            this->isSecend = false;
        }
        bool hasEnemy = false;
        for(auto i=scene->allLines[this->row]->zombies.begin();i!=scene->allLines[this->row]->zombies.end();i++)
        {
            if((*i)->zombienode->getPosition().x > this->plantnode->getPosition().x)
            {
                hasEnemy = true;
                break;
            }
        }
        if(hasEnemy && !this->isShooting)
        {
            this->plantnode->runAction(
                RepeatForever::create(Sequence::create(
                    DelayTime::create(1),
                    CallFunc::create([&](){
                        Sprite* peaNode = Sprite::create("豌豆.png");
                        Vec2 positon = this->plantnode->getPosition();
                        peaNode->setPosition(positon.x+100,positon.y-35);
                        this->scene->addChild(peaNode);
                        Pea* pea = new Pea(this->row,peaNode,this->scene);
                        this->scene->allProps.push_back(pea);
                        this->isSecend = true;
                    }),
                    NULL
                )));
            this->isShooting = true;
        }
        else if(!hasEnemy && this->isShooting)
        {
            this->plantnode->stopAllActions();
            this->isShooting = false;
        }
        return true;
    }
    return false;
}


