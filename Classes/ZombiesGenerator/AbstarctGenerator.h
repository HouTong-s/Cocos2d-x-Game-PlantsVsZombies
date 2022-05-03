#ifndef __ABSTRACTGENERATOR_H__
#define __ABSTRACTGENERATOR_H__

#include <chrono>
class GameScene;
class AbstarctGenerator
{
protected:
    void AddNormalZombie(int,GameScene*);
    void AddConeHeadZombie(int,GameScene*);
    void AddBucketZombie(int,GameScene*);
public:
    AbstarctGenerator();
    std::chrono::system_clock::time_point Start;
    virtual void execute(GameScene*,std::chrono::system_clock::time_point)=0;
    virtual ~AbstarctGenerator();
};

#endif
