//
//  StatePatternLayer.cpp
//  PatternsBundle
//
//  Created by fdp on 2018/2/13.
//
//

#include "StatePatternLayer.h"
auto &winSize = Director::getInstance()->getWinSize();
bool StatePatternLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    
    
    auto spr = Sprite::create("CloseNormal.png");
    spr->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
    this->addChild(spr);
    
    
    return true;
}
