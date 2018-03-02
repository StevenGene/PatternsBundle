//
//  StatePatternLayer.cpp
//  PatternsBundle
//
//  Created by fdp on 2018/2/13.
//
//

#include "StatePatternLayer.h"
#include "CommonUtils.hpp"

auto &winSize = Director::getInstance()->getWinSize();
bool StatePatternLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    
    auto btn1 = CommonUtils::createButton(CC_CALLBACK_2(StatePatternLayer::_onTouchEvent, this));
    btn1->setPosition(Vec2(winSize.width * 0.3, winSize.height * 0.2));
    btn1->setTitleText("Normal");
    btn1->setTag(int(TYPE_BTN_PRESSED::BTN_NORMAL));
    this->addChild(btn1);
    
    auto btn2 = CommonUtils::createButton(CC_CALLBACK_2(StatePatternLayer::_onTouchEvent, this));
    btn2->setPosition(Vec2(winSize.width * 0.6, winSize.height * 0.2));
    btn2->setTitleText("Attack");
    btn2->setTag(int(TYPE_BTN_PRESSED::BTN_ATTACK));
    this->addChild(btn2);
    
    auto btn3 = CommonUtils::createButton(CC_CALLBACK_2(StatePatternLayer::_onTouchEvent, this));
    btn3->setPosition(Vec2(winSize.width * 0.3, winSize.height * 0.3));
    btn3->setTitleText("Run");
    btn3->setTag(int(TYPE_BTN_PRESSED::BTN_RUN));
    this->addChild(btn3);
    
    _state = SoldierNormalState::create();
    _state->retain();

    return true;
}

void StatePatternLayer::_onTouchEvent(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type){
    Button *btn = dynamic_cast<Button*>(sender);
    TYPE_BTN_PRESSED btnType = (TYPE_BTN_PRESSED)btn->getTag();
    
    switch (type)
    {
        case Widget::TouchEventType::BEGAN:
            break;
            
        case Widget::TouchEventType::MOVED:
            break;
        case Widget::TouchEventType::CANCELED:
            break;
        case Widget::TouchEventType::ENDED:
        {
            if (_state) {
                auto tmpState = _state->handleInput(btnType);
                if (tmpState) {
                    CCLOG("rc:%ld",_state->getReferenceCount());

                    _state->release();

                    CCLOG("rc:%ld",_state->getReferenceCount());
                    CCLOG("-------------");

                    _state = tmpState;
                    CCLOG("rc:%ld",_state->getReferenceCount());

                    _state->retain();
                    CCLOG("rc:%ld",_state->getReferenceCount());

                }
            }
        }
            break;
    }
}

#pragma mark - ---------------- SoldierNormalState -------------------
bool SoldierNormalState::init(){
    CCLOG("Change to Normal State.");
    return true;
}

SoldierState *SoldierNormalState::handleInput(TYPE_BTN_PRESSED type){
    SoldierState *changeTo = nullptr;
    switch (type) {
        case TYPE_BTN_PRESSED::BTN_RUN:
        {
            changeTo = SoldierRunState::create();
        }
            break;
        case TYPE_BTN_PRESSED::BTN_ATTACK:
        {
            changeTo = SoldierAttackState::create();
        }
            break;
        default:
            break;
    }
    
    return changeTo;
}

#pragma mark - ---------------- SoldierRunState -------------------
bool SoldierRunState::init(){
    CCLOG("Change to Run State.");

    return true;
}

SoldierState *SoldierRunState::handleInput(TYPE_BTN_PRESSED type){
    SoldierState *changeTo = nullptr;
    switch (type) {
        case TYPE_BTN_PRESSED::BTN_NORMAL:
        {
            changeTo = SoldierNormalState::create();
        }
            break;
        default:
            break;
    }
    
    return changeTo;
}

#pragma mark - ---------------- SoldierAttackState -------------------
bool SoldierAttackState::init(){
    CCLOG("Change to Attack State.");

    return true;
}

SoldierState *SoldierAttackState::handleInput(TYPE_BTN_PRESSED type){
    SoldierState *changeTo = nullptr;
    switch (type) {
        case TYPE_BTN_PRESSED::BTN_NORMAL:
        {
            changeTo = SoldierNormalState::create();
        }
            break;
        default:
            break;
    }
    
    return changeTo;
}


