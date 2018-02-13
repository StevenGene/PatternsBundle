#ifndef __LAYER_MGR_H__
#define __LAYER_MGR_H__

#include "cocos2d.h"

class LayerMgr : public Ref
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(LayerMgr);
};

#endif // __LAYER_MGR_H__
