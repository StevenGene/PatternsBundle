//
//  StrategyLayer.h
//  PatternsBundle
//
//  Created by fdp on 2018/2/13.
//
//

#ifndef StrategyLayer_h
#define StrategyLayer_h

#include "CommonInclude.h"

enum TYPE_FLY{
    FLY_NORMAL,
    FLY_NO,
    FLY_ROCKET
};
class SoldierState;
class StrategyLayer : public Layer
{
public:
    CREATE_FUNC(StrategyLayer);
    virtual bool init();
};

class FlyBase: public Ref{
public:
    virtual void showFly() = 0;
    virtual bool init();
};

class NormalFly : public FlyBase{
public:
    CREATE_FUNC(NormalFly);

    virtual void showFly();
};

class CannotFly : public FlyBase{
public:
    CREATE_FUNC(CannotFly);

    virtual void showFly();
};

class RocketFly : public FlyBase{
public:
    CREATE_FUNC(RocketFly);

    virtual void showFly();
};

#pragma mark - --------- FlyMgr ----------
class FlyMgr : public Ref{
public:
    CREATE_FUNC(FlyMgr);
    virtual bool init();

    FlyBase *addFlyByType(TYPE_FLY type);
    void showFly();
private:
    FlyBase *_fly;
};

#endif /* StrategyLayer_h */
