#include "cocos2d.h"

class PauseScene:public cocos2d::Scene
{
public:
    virtual bool init();  
    static cocos2d::Scene* createScene(cocos2d::RenderTexture*);
    CREATE_FUNC(PauseScene);
};
