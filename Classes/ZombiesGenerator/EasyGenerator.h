#ifndef __EASYGENERATOR_H__
#define __EASYGENERATOR_H__

#include"AbstarctGenerator.h"
class EasyGenerator : public AbstarctGenerator
{
public:
    EasyGenerator();
    ~EasyGenerator();
    virtual void execute(GameScene*);
};

#endif
