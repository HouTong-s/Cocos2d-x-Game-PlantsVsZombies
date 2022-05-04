#ifndef __FIRSTGENERATOR_H__
#define __FIRSTGENERATOR_H__

#include"AbstarctGenerator.h"
class FirstGenerator : public AbstarctGenerator
{
public:
    FirstGenerator();
    ~FirstGenerator();
    virtual void execute(GameScene*);
};

#endif
