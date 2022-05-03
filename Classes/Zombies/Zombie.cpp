#include "Zombie.h"
using namespace std;
using namespace cocos2d;
Zombie::Zombie(int row,Sprite* node)
{
    this->row = row;
    this->zombienode = node;
    node->setPosition(ScreenWidth,640-Lawn_Height*row);
    this->lifeValue = 10;
    this->EatStart = chrono::system_clock::now();
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
