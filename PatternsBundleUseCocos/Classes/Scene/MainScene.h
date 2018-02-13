#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "CommonInclude.h"

class MainScene : public Scene
{
public:
    CREATE_FUNC(MainScene);
    virtual bool init();
};

#endif // __MAIN_SCENE_H__
