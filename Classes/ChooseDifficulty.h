#ifndef __ChooseDifficulty_SCENE_H__
#define __ChooseDifficulty_SCENE_H__

#include "cocos2d.h"
#include <string>

class ChooseDifficulty : public cocos2d::Scene
{
public:

    static cocos2d::Scene* createScene();

    virtual bool init();
    
    void ChooseDifficultyCallback(cocos2d::Ref* pSender,std::string,int);
    
    CREATE_FUNC(ChooseDifficulty);
};

#endif 
