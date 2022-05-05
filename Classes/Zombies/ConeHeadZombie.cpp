#include "ConeHeadZombie.h"
using namespace cocos2d;
using namespace std;
ConeHeadZombie::ConeHeadZombie(int row,Sprite* node): NormalZombie(row,node)
{
    this->lifeValue = 30;
    node->setContentSize(Size(110, 160));
}

ConeHeadZombie::~ConeHeadZombie()
{
}

void ConeHeadZombie::ExamineToChangeTexture()
{
    if(this->lifeValue <= 24 && this->lifeValue >= 19)
    {
        this->zombienode->setTexture("路障僵尸2.png");
        this->zombienode->setContentSize(Size(110, 160));
    }
    else if(this->lifeValue < 19 && this->lifeValue >= 11)
    {
        this->zombienode->setTexture("路障僵尸3.png");
        this->zombienode->setContentSize(Size(110, 160));
    }
    else if(this->lifeValue > 0 && this->lifeValue <= 10)
    {
        this->zombienode->setTexture("普通僵尸.png");
        this->zombienode->setContentSize(Size(96, 140));
    }
}

