#ifndef __DATASTRUCTURES_H__
#define __DATASTRUCTURES_H__
#include<vector>
#include"cocos2d.h"

#define MyLeft 390
#define MyTop 689
//Line记录一条线上的所有植物和僵尸
class Zombie;
class Plant;
struct Line
{
    std::vector<Zombie*> zombies;
    std::vector<Plant*> plants;
};
//用于点击的时候迭代
struct MyRect
{
    //是否是空草地
    bool isLawn;
    int row;
    int column;
};
//判断两个区域是否碰撞

#endif
