#include "EasyGenerator.h"
#include "cocos2d.h"
#include <math.h>
#include "../GameScenes/GameScene.h"
using namespace cocos2d;
using namespace std;
EasyGenerator::EasyGenerator()
{
}

EasyGenerator::~EasyGenerator()
{
}

void EasyGenerator::execute(GameScene *scene)
{
    auto end = chrono::system_clock::now();
    if(scene->ZombiesToGenerate > 0)
    {
        chrono::duration<double> diff = end - this->Start;
        auto interval = diff.count();
        if(interval > 17 && interval <= 55)
        {
            double remainder = fmod(interval, 12);
            if(remainder < 0.009 || 12- remainder <0.009)
            {
                int linenum = rand()%5;
                AddNormalZombie(linenum, scene);
                scene->ZombiesToGenerate --;
            }
        }
        else if(interval > 55 && interval <= 100)
        {
            double remainder = fmod(interval, 10);
            if(remainder < 0.009 || 10- remainder <0.009)
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
        else if(interval > 100 && interval <= 160)
        {
            double remainder = fmod(interval, 7);
            if(remainder <0.009 || 7- remainder <0.009)
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
        else if(interval > 160 && interval <= 210)
        {
            double remainder = fmod(interval, 6);
            if(remainder < 0.009 || 6- remainder <0.009)
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
        else if(interval > 210)
        {
            double remainder = fmod(interval, 4);
            if(remainder < 0.009 || 4- remainder <0.009)
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

