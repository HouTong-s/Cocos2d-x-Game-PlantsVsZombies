#include "Zombie.h"
using namespace std;
using namespace cocos2d;
const int Zombie::moveTag = 0;
const int Zombie::eatTag = 1;
const int Zombie::slowTag = 2;
Zombie::Zombie(int row,Sprite* node)
{
    this->row = row;
    this->zombienode = node;
    node->setPosition(ScreenWidth,640-Lawn_Height*row);
}

Zombie::~Zombie()
{
}

bool Zombie::IsAlive()
{
    return this->lifeValue > 0;
}

bool Zombie::move(std::vector<Line*> allLines)
{
    if(IsAlive())
    {
        ExamineToChangeTexture();
        return DoSelfTask(allLines);
    }
    else
    {
        return false;
    }
}
void Zombie::putSlow(int slowtime)
{
    this->isSlowed = true;
    if(this->zombienode->getActionByTag(Zombie::slowTag) != nullptr)
    {
        this->zombienode->stopActionByTag(Zombie::slowTag);
    }
    auto act = Sequence::create(
        DelayTime::create(slowtime),
        CallFunc::create([&](){
            this->isSlowed = false;
        }),
        NULL
    );
    this->zombienode->runAction(act);
    act->setTag(Zombie::slowTag);
}
