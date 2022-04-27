#include "NormalZombie.h"
using namespace cocos2d;
using namespace std;
NormalZombie::NormalZombie(int row,Sprite* node): Zombie(row,node)
{
    this->lifeValue = 10;
    node->setContentSize(Size(96, 140));
}

NormalZombie::~NormalZombie()
{
}

void NormalZombie::ExamineToChangeTexture()
{
    
}
