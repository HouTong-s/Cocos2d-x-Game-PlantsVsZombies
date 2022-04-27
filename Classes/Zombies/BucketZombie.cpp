#include "BucketZombie.h"
using namespace cocos2d;
using namespace std;
BucketZombie::BucketZombie(int row,Sprite* node): Zombie(row,node)
{
    this->lifeValue = 60;
    node->setContentSize(Size(110, 160));
}

BucketZombie::~BucketZombie()
{
}

void BucketZombie::ExamineToChangeTexture()
{
    if(this->lifeValue <= 46 && this->lifeValue >= 29)
    {
        this->zombienode->setTexture("铁桶僵尸2.png");
        this->zombienode->setContentSize(Size(110, 160));
    }
    else if(this->lifeValue < 29 && this->lifeValue >= 11)
    {
        this->zombienode->setTexture("铁桶僵尸3.png");
        this->zombienode->setContentSize(Size(110, 160));
    }
    else if(this->lifeValue > 0 && this->lifeValue <= 10)
    {
        this->zombienode->setTexture("普通僵尸.png");
        this->zombienode->setContentSize(Size(96, 140));
    }
}

