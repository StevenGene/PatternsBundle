#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "CommonInclude.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(HelloWorld);
};

#endif // __MAIN_SCENE_H__
