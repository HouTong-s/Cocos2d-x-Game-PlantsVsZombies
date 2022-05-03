#ifndef __DATASTRUCTURES_H__
#define __DATASTRUCTURES_H__

#include<vector>
#include"cocos2d.h"

//以下为屏幕的长宽
#define ScreenWidth 1422
#define ScreenHeight 800

//以下为草坪最左上角的横纵坐标
#define Lawn_Left 390
#define Lawn_Top 689

//以下为每块草地的宽度和高度
#define Lawn_Width 103
#define Lawn_Height 121

class Zombie;
class Plant;
//Line记录一条线上的所有植物和僵尸
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

#endif
