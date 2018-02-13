#ifndef __MAIN_LAYER_H__
#define __MAIN_LAYER_H__

#include "CommonInclude.h"

class MainLayer : public Layer
{
public:
    CREATE_FUNC(MainLayer);
    virtual bool init();
    
    void addPatterns();
};

#endif // __MAIN_LAYER_H__
