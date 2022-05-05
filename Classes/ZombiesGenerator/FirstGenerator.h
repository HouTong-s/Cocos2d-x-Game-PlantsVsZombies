#ifndef __FIRSTGENERATOR_H__
#define __FIRSTGENERATOR_H__

#include"AbstarctGenerator.h"
class FirstGenerator : public AbstarctGenerator
{
public:
    FirstGenerator();
    ~FirstGenerator();
    virtual void execute(GameScene*,std::chrono::system_clock::time_point);
};

#endif
