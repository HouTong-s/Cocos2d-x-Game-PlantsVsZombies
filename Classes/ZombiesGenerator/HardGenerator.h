#ifndef __HARDGENERATOR_H__
#define __HARDGENERATOR_H__

#include"AbstarctGenerator.h"
class HardGenerator : public AbstarctGenerator
{
public:
    HardGenerator();
    ~HardGenerator();
    virtual void execute(GameScene*);
};

#endif
