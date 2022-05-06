#include "NormalZombie.h"
#include"../Plants/Plant.h"
using namespace cocos2d;
using namespace std;
NormalZombie::NormalZombie(int row,Sprite* node): Zombie(row,node)
{
    this->lifeValue = 10;
    node->setContentSize(Size(96, 140));
    Action* act = MoveTo::create(float(ScreenWidth - 300) / this->speed, Vec2(300, this->zombienode->getPosition().y));
    node->runAction(act);
    act->setTag(Zombie::moveTag);
}

NormalZombie::~NormalZombie()
{
}

void NormalZombie::ExamineToChangeTexture()
{
    
}
bool NormalZombie::DoSelfTask(vector<Line *> allLines)
{
    //如果僵尸走到目的地了也返回false
    if(this->zombienode->getPosition().x <= 300)
    {
        return false;
    }
    float CurentSpeed = this->speed;
    if(this->isSlowed)
    {
        CurentSpeed /=2;
    }
    //isStopped为true时，意味着僵尸站着不动，以及开始吃植物
    bool isStopped = false;
    for(auto i=allLines[this->row]->plants.begin();i!=allLines[this->row]->plants.end();i++)
    {
        if(*i != nullptr &&
           (*i)->plantnode->getBoundingBox().containsPoint(this->zombienode->getPosition()))
        {
            isStopped = true;
            if(this->zombienode->getActionByTag(Zombie::eatTag) == nullptr)
            {
                (*i)->lifeValue --;
                float temp = 1;
                if(this->isSlowed)
                {
                    temp = 1.5;
                }
                auto act = DelayTime::create(temp);
                this->zombienode->runAction(act);
                act->setTag(Zombie::eatTag);
            }
            break;
        }
    }
    if(isStopped)
    {
        if(this->isWalking)
        {
            this->zombienode->stopActionByTag(Zombie::moveTag);
            this->isWalking = false;
        }
    }
    else
    {
        Vec2 rect = this->zombienode->getPosition();
        if(!this->isWalking)
        {
            Action* act = MoveTo::create(float(rect.x - 300) / CurentSpeed, Vec2(300, rect.y));
            this->zombienode->runAction(act);
            act->setTag(Zombie::moveTag);
            this->isWalking = true;
        }
        else
        {
            if(this->isSlowed && !this->slowWalking)
            {
                this->zombienode->stopActionByTag(Zombie::moveTag);
                Action* act = MoveTo::create(float(rect.x - 300) / CurentSpeed, Vec2(300, rect.y));
                this->zombienode->runAction(act);
                act->setTag(Zombie::moveTag);
                this->slowWalking = true;
            }
            else if( !this->isSlowed && this->slowWalking)
            {
                this->zombienode->stopActionByTag(Zombie::moveTag);
                Action* act = MoveTo::create(float(rect.x - 300) / CurentSpeed, Vec2(300, rect.y));
                this->zombienode->runAction(act);
                act->setTag(Zombie::moveTag);
                this->slowWalking = false;
            }
        }
    }
    return true;
}
