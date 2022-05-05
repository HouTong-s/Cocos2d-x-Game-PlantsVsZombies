#include "AbstarctGenerator.h"
#include"../Zombies/AllZombies.h"
#include"cocos2d.h"
#include"../GameScenes/GameScene.h"
using namespace cocos2d;
AbstarctGenerator::AbstarctGenerator()
{
    this->Start = std::chrono::system_clock::now();
}

AbstarctGenerator::~AbstarctGenerator()
{
}

void AbstarctGenerator::AddNormalZombie(int row,GameScene* scene)
{
    Sprite* zombieNode = Sprite::create("普通僵尸.png");
    scene->addChild(zombieNode,10*row);
    NormalZombie* zombie = new NormalZombie(row,zombieNode);
    scene->allLines[row]->zombies.push_back(zombie);
}

void AbstarctGenerator::AddConeHeadZombie(int row,GameScene* scene)
{
    Sprite* zombieNode = Sprite::create("路障僵尸1.png");
    scene->addChild(zombieNode,10*row);
    ConeHeadZombie* zombie = new ConeHeadZombie(row,zombieNode);
    scene->allLines[row]->zombies.push_back(zombie);
}

void AbstarctGenerator::AddBucketZombie(int row,GameScene* scene)
{
    Sprite* zombieNode = Sprite::create("铁桶僵尸1.png");
    scene->addChild(zombieNode,10*row);
    BucketZombie* zombie = new BucketZombie(row,zombieNode);
    scene->allLines[row]->zombies.push_back(zombie);
}
