//
//  StrategyLayer.cpp
//  PatternsBundle
//
//  Created by fdp on 2018/2/13.
//
//

#include "StrategyLayer.h"
#include "CommonUtils.hpp"

bool StrategyLayer::init(){
    if (!Layer::init()) {
        return false;
    }

    auto mgr = FlyMgr::create();
    mgr->retain();
    
    auto concreteFly = mgr->addFlyByType(TYPE_FLY::FLY_NO);
    concreteFly->showFly();
    
    auto concreteFly2 = mgr->addFlyByType(TYPE_FLY::FLY_ROCKET);
    concreteFly2->showFly();
    
    auto concreteFly3 = mgr->addFlyByType(TYPE_FLY::FLY_NORMAL);
    concreteFly3->showFly();
    
    mgr->showFly();
    return true;
}

bool FlyBase::init(){
    return true;
}

void NormalFly::showFly(){
    CCLOG("normal fly");
};

void CannotFly::showFly(){
    CCLOG("can not fly");
};

void RocketFly::showFly(){
    CCLOG("rocket fly");
};


#pragma mark - ---------- FlyMgr -----------

bool FlyMgr::init(){
    return true;
}

FlyBase *FlyMgr::addFlyByType(TYPE_FLY type){
    switch (type) {
        case TYPE_FLY::FLY_NORMAL:
        {
            _fly = NormalFly::create();
        }
            break;
        case TYPE_FLY::FLY_NO:
        {
            _fly = CannotFly::create();
        }
            break;
        case TYPE_FLY::FLY_ROCKET:
        {
            _fly = RocketFly::create();
        }
            break;
        default:
            break;
    }
    return _fly;
}

void FlyMgr::showFly(){
    _fly->showFly();
}


