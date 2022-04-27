#include "FirstGenerator.h"
#include"../Zombies/AllZombies.h"
#include"cocos2d.h"
#include"stdlib.h"
#include <math.h>
#include <time.h>
#include"../GameScene.h"
using namespace cocos2d;
using namespace std;
FirstGenerator::FirstGenerator()
{
}

FirstGenerator::~FirstGenerator()
{
}

void FirstGenerator::execute(GameScene *scene,chrono::system_clock::time_point end)
{
    if(scene->ZombiesToGenerate > 0)
    {
        chrono::duration<double> diff = end - this->Start;
        auto interval = diff.count();
        srand(time(0));
        if(interval > 0 && interval <= 17)
        {
            double remainder = fmod(interval, 8);
            if(remainder < 0.009 || 8- remainder <0.009)
            {
                int linenum = rand()%5;
                AddNormalZombie(linenum, scene);
                scene->ZombiesToGenerate -= 1;
            }
        }
        else if(interval > 17 && interval <= 50)
        {
            double remainder = fmod(interval, 6);
            if(remainder < 0.009 || 6- remainder <0.009)
            {
                int linenum = rand()%5;
                int i = rand()%2;
                if(i == 0)
                {
                    AddNormalZombie(linenum, scene);
                }
                else if(i == 1)
                {
                    AddConeHeadZombie(linenum, scene);
                }
                scene->ZombiesToGenerate -= 1;
            }
        }
        else if(interval > 50 && interval <= 70)
        {
            double remainder = fmod(interval, 4);
            if(remainder <0.009 || 4- remainder <0.009)
            {
                int linenum = rand()%5;
                int i = rand()%3;
                if(i == 0)
                {
                    AddNormalZombie(linenum, scene);
                }
                else if(i == 1)
                {
                    AddConeHeadZombie(linenum, scene);
                }
                else
                {
                    AddBucketZombie(linenum, scene);
                }
                scene->ZombiesToGenerate -= 1;
            }
        }
        else if(interval > 70)
        {
            double remainder = fmod(interval, 1);
            if(remainder < 0.009 || 1- remainder <0.009)
            {
            
                int linenum = rand()%5;
                int i = rand()%2;
                if(i == 0)
                {
                    AddConeHeadZombie(linenum, scene);
                }
                else if(i == 1)
                {
                    AddBucketZombie(linenum, scene);
                }
                scene->ZombiesToGenerate -= 1;
            }
        }
    }
}

