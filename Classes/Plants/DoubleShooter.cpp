#include "DoubleShooter.h"
#include "../GameScene.h"
#include "../Board/DataStructures.h"
#include"../Zombies/Zombie.h"
#include "Pea.h"
#include"stdlib.h"
#include<math.h>
using namespace cocos2d;
using namespace std;
DoubleShooter::DoubleShooter(int row,int col,Sprite* node):Plant(row,col,node)
{
}

DoubleShooter::~DoubleShooter()
{
}
bool DoubleShooter::DoSelfTask(GameScene* scene)
{
    if(this->plantnode != nullptr)
    {
        if(this->isSecend)
        {
            Sprite* peaNode = Sprite::create("豌豆.png");
            Vec2 positon = this->plantnode->getPosition();
            peaNode->setPosition(positon.x+100,positon.y-50);
            scene->addChild(peaNode);
            Pea* pea = new Pea(this->row,this->column,peaNode);
            scene->allProps.push_back(pea);
            this->isSecend = false;
        }
        
        auto end = chrono::system_clock::now();
        chrono::duration<double> diff = end - this->start;
        if(diff.count() > 0.99)
        {
            this->start = end;
            for(auto i=scene->allLines[this->row]->zombies.begin();i!=scene->allLines[this->row]->zombies.end();i++)
            {
                if((*i)->zombienode->getPosition().x > this->plantnode->getPosition().x)
                {
                    //CCLOG("%d线发射 总共%d %d %d僵尸",this->row,scene->allLines[this->row]->zombies.size(),scene->allLines[0]->zombies.size(),scene->allLines[1]->zombies.size());
                    Sprite* peaNode = Sprite::create("豌豆.png");
                    Vec2 positon = this->plantnode->getPosition();
                    peaNode->setPosition(positon.x+100,positon.y-35);
                    scene->addChild(peaNode);
                    Pea* pea = new Pea(this->row,this->column,peaNode);
                    scene->allProps.push_back(pea);
                    this->isSecend = true;
                    break;
                }
            }
        }
        return true;
    }
    return false;
}


