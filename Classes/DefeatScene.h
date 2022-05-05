#ifndef __DefeatScene_SCENE_H__
#define __DefeatScene_SCENE_H__

#include "cocos2d.h"

class DefeatScene : public cocos2d::Scene
{
public:

    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(DefeatScene);
};

#endif 
