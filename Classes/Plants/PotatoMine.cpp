#include "PotatoMine.h"
#include "../GameScenes/GameScene.h"
#include "../Board/DataStructures.h"
#include"../Zombies/Zombie.h"
using namespace cocos2d;
using namespace std;
PotatoMine::PotatoMine(int row,int col,Sprite* node,GameScene* scene):Plant(row,col,node,scene)
{
    node->runAction(Sequence::create(
        DelayTime::create(10),
        CallFunc::create([&](){
            if(this->lifeValue > 0)
            {
                this->isReady = true;
                //防止准备好的土豆地雷被吃掉，所以加点生命值
                this->lifeValue = 10;
                this->plantnode->setTexture("土豆地雷2.png");
                this->plantnode->setContentSize(Size(103, 121));
            }
        }),
        NULL
    ));
}

PotatoMine::~PotatoMine()
{
}
bool PotatoMine::DoSelfTask()
{
    if(this->plantnode != nullptr)
    {
        if(this->isReady)
        {
            bool isBoom = false;
            for(auto i=scene->allLines[this->row]->zombies.begin();i!=scene->allLines[this->row]->zombies.end();i++)
            {
                Rect rect = this->plantnode->getBoundingBox();
                //以下操作使得土豆雷爆炸时，形成小范围的范围伤害
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
                return false;
            }
        }
        return true;
    }
    return false;
}

