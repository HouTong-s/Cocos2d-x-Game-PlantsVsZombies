#include "Zombie.h"
#include"../Plants/Plant.h"
#include"stdlib.h"
#include<math.h>
using namespace std;
using namespace cocos2d;
Zombie::Zombie(int row,Sprite* node)
{
    this->row = row;
    this->zombienode = node;
    node->setPosition(1422,634-118*row);
    //node->setContentSize(Size(96, 140));
    this->lifeValue = 10;
    this->EatStart = chrono::system_clock::now();
    this->zombienode->runAction(MoveTo::create(float(1322) / this->speed, Vec2(100, 624-118*row)));
}

Zombie::~Zombie()
{
}

bool Zombie::IsAlive()
{
    //CCLOG("%d", this->lifeValue);
    return this->lifeValue > 0;
}

bool Zombie::move(std::vector<Line*> allLines)
{
    if(IsAlive())
    {
        ExamineToChangeTexture();
        float CurentSpeed = this->speed;
        if(this->isSlowed)
        {
            CurentSpeed /=2;
            auto end = chrono::system_clock::now();
            chrono::duration<double> diff = end - this->SlowStart;
            if(diff.count() >= this->slowtime)
            {
                this->slowtime = 0;
                CurentSpeed = this->speed;
                this->isSlowed = false;
            }
        }
        bool isStopped = false;
        for(auto i=allLines[this->row]->plants.begin();i!=allLines[this->row]->plants.end();i++)
        {
            if(*i != nullptr &&
               (*i)->plantnode->getBoundingBox().containsPoint(this->zombienode->getPosition()))
            {
                this->zombienode->stopAllActions();
                auto end = chrono::system_clock::now();
                chrono::duration<double> diff = end - this->EatStart;
                if(diff.count() > 0.99)
                {
                    this->EatStart = end;
                    //CCLOG("eat");
                    (*i)->lifeValue -= 1;
                }
                isStopped = true;
                break;
            }
        }
        if(isStopped)
        {
            if(this->hasAction)
            {
                this->zombienode->stopAllActions();
                this->hasAction = false;
            }
        }
        else
        {
            Vec2 rect = this->zombienode->getPosition();
            if(!this->hasAction)
            {
                this->zombienode->runAction(MoveTo::create(float(rect.x - 100) / CurentSpeed, Vec2(100, rect.y)));
                this->hasAction = true;
            }
            else
            {
                if(this->isSlowed && !this->slowWalking)
                {
                    //CCLOG("减速");
                    this->zombienode->stopAllActions();
                    this->zombienode->runAction(MoveTo::create(float(rect.x - 100) / CurentSpeed, Vec2(100, rect.y)));
                    this->slowWalking = true;
                }
                else if( !this->isSlowed && this->slowWalking)
                {
                    //CCLOG("恢复速度");
                    this->zombienode->stopAllActions();
                    this->zombienode->runAction(MoveTo::create(float(rect.x - 100) / CurentSpeed, Vec2(100, rect.y)));
                    this->slowWalking = false;
                }
            }
            if(rect.x > 100)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
