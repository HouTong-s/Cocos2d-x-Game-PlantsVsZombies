#include "NormalZombie.h"
#include"../Plants/Plant.h"
using namespace cocos2d;
using namespace std;
NormalZombie::NormalZombie(int row,Sprite* node): Zombie(row,node)
{
    this->lifeValue = 10;
    node->setContentSize(Size(96, 140));
    node->runAction(MoveTo::create(float(ScreenWidth - 300) / this->speed, Vec2(300, 640-Lawn_Height*row)));
}

NormalZombie::~NormalZombie()
{
}

void NormalZombie::ExamineToChangeTexture()
{
    
}
bool NormalZombie::DoSelfTask(vector<Line *> allLines)
{
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
            //被减速了也会减少攻击速度
            if(diff.count() > (this->isSlowed ? 1.49 : 0.99))
            {
                this->EatStart = end;
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
                this->zombienode->stopAllActions();
                this->zombienode->runAction(MoveTo::create(float(rect.x - 100) / CurentSpeed, Vec2(100, rect.y)));
                this->slowWalking = true;
            }
            else if( !this->isSlowed && this->slowWalking)
            {
                this->zombienode->stopAllActions();
                this->zombienode->runAction(MoveTo::create(float(rect.x - 100) / CurentSpeed, Vec2(100, rect.y)));
                this->slowWalking = false;
            }
        }
    }
    return true;
}
