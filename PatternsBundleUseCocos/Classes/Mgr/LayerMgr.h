#ifndef __LAYER_MGR_H__
#define __LAYER_MGR_H__

#include "CommonInclude.h"

class LayerMgr
{
public:
    static LayerMgr* getInstance();
    void initScene();
private:
    Scene *_mainScene;
};

#endif // __LAYER_MGR_H__
