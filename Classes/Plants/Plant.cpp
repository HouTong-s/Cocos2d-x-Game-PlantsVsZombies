#include"Plant.h"
using namespace cocos2d;
using namespace std;

const vector<string> Plant::PlantsNames = {"向日葵","豌豆射手","寒冰射手","坚果","土豆雷","双发射手"};
const vector<int> Plant::CardCost = {50,100,150,50,25,200};
const vector<string> Plant::CardImgs = {"向日葵卡.png","豌豆射手卡.png","寒冰射手卡.png","坚果卡.png","土豆地雷卡.png","双发射手卡.png"};
const vector<string> Plant::PlantsImgs = {"向日葵.png","豌豆射手.png","寒冰射手.png","坚果.png","土豆地雷1.png","双发射手.png"};
const vector<int> Plant::CoolTimes = {5,3,3,15,15,3};
Plant::Plant(int row,int col,Sprite* node)
{
    this->row = row;
    this->column = col;
    this->plantnode = node;
    this->start = chrono::system_clock::now();
}

Plant::~Plant()
{
}

bool Plant::IsAlive()
{
    return this->lifeValue > 0;
}
//execute返回false时，plant对象就将被删除
bool Plant::execute(GameScene* scene)
{
    if(IsAlive())
    {
        //DoSelfTask一般来说只有在子弹碰到僵尸才会返回false，除非发生特殊情况，plantnode被清除了
        return DoSelfTask(scene);
    }
    else
    {
        this->plantnode->setTexture("草地块.png");
        return false;
    }
}
