#include "IceShooter.h"
#include "../GameScenes/GameScene.h"
#include "../Board/DataStructures.h"
#include"../Zombies/Zombie.h"
#include "../Props/IcePea.h"
using namespace cocos2d;
using namespace std;
IceShooter::IceShooter(int row,int col,Sprite* node,GameScene* scene):Plant(row,col,node,scene)
{
}

IceShooter::~IceShooter()
{
}
bool IceShooter::DoSelfTask()
{
    if(this->plantnode != nullptr)
    {
        bool hasEnemy = false;
        for(auto i=scene->allLines[this->row]->zombies.begin();i!=scene->allLines[this->row]->zombies.end();i++)
        {
            if((*i)->zombienode->getPosition().x > this->plantnode->getPosition().x)
            {
                //CCLOG("detect");
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
                        Sprite* peaNode = Sprite::create("寒冰豌豆.png");
                        Vec2 positon = this->plantnode->getPosition();
                        peaNode->setPosition(positon.x+100,positon.y-35);
                        this->scene->addChild(peaNode);
                        IcePea* pea = new IcePea(this->row,peaNode,this->scene);
                        this->scene->allProps.push_back(pea);
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


