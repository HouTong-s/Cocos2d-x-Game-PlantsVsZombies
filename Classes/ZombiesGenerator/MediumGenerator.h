#ifndef __MEDUIMGENERATOR_H__
#define __MEDUIMGENERATOR_H__

#include"AbstarctGenerator.h"
class MediumGenerator : public AbstarctGenerator
{
public:
    MediumGenerator();
    ~MediumGenerator();
    virtual void execute(GameScene*);
};

#endif
