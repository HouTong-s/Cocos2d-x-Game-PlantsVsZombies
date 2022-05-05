#include "PeaShooter.h"
#include "../GameScene.h"
#include "../Board/DataStructures.h"
#include"../Zombies/Zombie.h"
#include "Pea.h"
using namespace cocos2d;
using namespace std;
PeaShooter::PeaShooter(int row,int col,Sprite* node):Plant(row,col,node)
{
}

PeaShooter::~PeaShooter()
{
}
bool PeaShooter::DoSelfTask(GameScene* scene)
{
    if(this->plantnode != nullptr)
    {
        auto end = chrono::system_clock::now();
        chrono::duration<double> diff = end - this->start;
        if(diff.count() > 0.99  )
        {
            this->start = end;
            for(auto i=scene->allLines[this->row]->zombies.begin();i!=scene->allLines[this->row]->zombies.end();i++)
            {
                if((*i)->zombienode->getPosition().x > this->plantnode->getPosition().x)
                {
                    Sprite* peaNode = Sprite::create("豌豆.png");
                    Vec2 positon = this->plantnode->getPosition();
                    peaNode->setPosition(positon.x+100,positon.y-35);
                    scene->addChild(peaNode);
                    Pea* pea = new Pea(this->row,this->column,peaNode);
                    scene->allProps.push_back(pea);
                    break;
                }
            }
        }
        return true;
    }
    return false;
}

