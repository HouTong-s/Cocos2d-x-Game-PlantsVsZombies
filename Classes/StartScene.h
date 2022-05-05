#ifndef __StartScene_SCENE_H__
#define __StartScene_SCENE_H__

#include "cocos2d.h"

class StartScene : public cocos2d::Scene
{
public:

    static cocos2d::Scene* createScene();

    virtual bool init();

    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void menuStartCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(StartScene);
};

#endif 
