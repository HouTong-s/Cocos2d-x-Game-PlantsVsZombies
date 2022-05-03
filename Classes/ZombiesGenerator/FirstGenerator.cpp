#include "FirstGenerator.h"
#include"../Zombies/AllZombies.h"
#include"cocos2d.h"
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
        else if(interval > 35 && interval <= 70)
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
        else if(interval > 70 && interval <= 100)
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
                    int i = rand()%3;
                    while (scene->ZombiesToGenerate >0 && num>0)
                    {
                        linenum = (linenum+1)%5;
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
        else if(interval > 100 && interval <= 150)
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
                    int i = rand()%5;
                    while (scene->ZombiesToGenerate >0 && num>0)
                    {
                        linenum = (linenum+1)%5;
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
        else if(interval > 150)
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
                    int i = rand()%5;
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

