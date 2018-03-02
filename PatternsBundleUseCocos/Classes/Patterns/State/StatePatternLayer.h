//
//  StatePatternLayer.h
//  PatternsBundle
//
//  Created by fdp on 2018/2/13.
//
//

#ifndef StatePatternLayer_h
#define StatePatternLayer_h

#include "CommonInclude.h"

enum SOLDIER_STATE{
    NORMAL,
    RUN,
    JUMP,
    ATTACK,
    DIE
};

enum TYPE_BTN_PRESSED{
    BTN_NORMAL,
    BTN_RUN,
    BTN_JUMP,
    BTN_ATTACK,
    BTN_DIE

};

class SoldierState;
class StatePatternLayer : public Layer
{
public:
    CREATE_FUNC(StatePatternLayer);
    virtual bool init();
private:
    void _onTouchEvent(cocos2d::Ref* sender,Widget::TouchEventType type);
    SoldierState *_state;
};

class SoldierState : public Ref {
public:
    virtual SoldierState *handleInput(TYPE_BTN_PRESSED type) = 0;
};

class SoldierNormalState : public SoldierState{
public:
    CREATE_FUNC(SoldierNormalState);
    virtual bool init();
    virtual SoldierState *handleInput(TYPE_BTN_PRESSED type);
};

class SoldierRunState : public SoldierState{
public:
    CREATE_FUNC(SoldierRunState);
    virtual bool init();
    virtual SoldierState *handleInput(TYPE_BTN_PRESSED type);
};


class SoldierAttackState : public SoldierState{
public:
    CREATE_FUNC(SoldierAttackState);
    virtual bool init();
    virtual SoldierState *handleInput(TYPE_BTN_PRESSED type);
};

#endif /* StatePatternLayer_h */
