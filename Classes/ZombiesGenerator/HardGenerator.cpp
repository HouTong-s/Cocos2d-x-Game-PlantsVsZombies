#include "HardGenerator.h"
#include "cocos2d.h"
#include <math.h>
#include "../GameScenes/GameScene.h"
using namespace cocos2d;
using namespace std;
HardGenerator::HardGenerator()
{
}

HardGenerator::~HardGenerator()
{
}

void HardGenerator::execute(GameScene *scene)
{
    auto end = chrono::system_clock::now();
    if(scene->ZombiesToGenerate > 0)
    {
        chrono::duration<double> diff = end - this->Start;
        auto interval = diff.count();
        if(interval > 15 && interval <= 35)
        {
            double remainder = fmod(interval, 8);
            if(remainder < 0.009 || 8- remainder <0.009)
            {
                int linenum = rand()%5;
                AddNormalZombie(linenum, scene);
                scene->ZombiesToGenerate --;
            }
        }
        else if(interval > 35 && interval <= 80)
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
                scene->ZombiesToGenerate --;
            }
        }
        else if(interval > 80 && interval <= 140)
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
                scene->ZombiesToGenerate --;
            }
            else
            {
                remainder = fmod(interval, 10);
                if(remainder <0.009 || 10- remainder <0.009)
                {
                    int num = 4;
                    int linenum = rand()%5;
                    int i ;
                    while (scene->ZombiesToGenerate >0 && num>0)
                    {
                        linenum = (linenum+1)%5;
                        i = rand()%3;
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
                        num -- ;
                        scene->ZombiesToGenerate --;
                    }
                }
            }
        }
        else if(interval > 140 && interval <= 180)
        {
            double remainder = fmod(interval, 3);
            if(remainder < 0.009 || 3- remainder <0.009)
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
                scene->ZombiesToGenerate --;
            }
            else
            {
                remainder = fmod(interval, 10);
                if(remainder <0.009 || 10- remainder <0.009)
                {
                    int num = 6;
                    int linenum = rand()%5;
                    int i;
                    while (scene->ZombiesToGenerate >0 && num>0)
                    {
                        linenum = (linenum+1)%5;
                        i = rand()%5;
                        if(i == 0 || i == 1)
                        {
                            AddConeHeadZombie(linenum, scene);
                        }
                        else
                        {
                            AddBucketZombie(linenum, scene);
                        }
                        num -- ;
                        scene->ZombiesToGenerate --;
                    }
                }
            }
        }
        else if(interval > 180)
        {
            double remainder = fmod(interval, 2);
            if(remainder < 0.009 || 2- remainder <0.009)
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
                scene->ZombiesToGenerate --;
            }
            else
            {
                remainder = fmod(interval, 8);
                if(remainder <0.009 || 8- remainder <0.009)
                {
                    int num = 10;
                    int linenum = rand()%5;
                    int i ;
                    while (scene->ZombiesToGenerate >0 && num>0)
                    {
                        linenum = (linenum+1)%5;
                        i = rand()%5;
                        if(i == 0 )
                        {
                            AddConeHeadZombie(linenum, scene);
                        }
                        else
                        {
                            AddBucketZombie(linenum, scene);
                        }
                        num -- ;
                        scene->ZombiesToGenerate --;
                    }
                }
            }
        }
    }
}

