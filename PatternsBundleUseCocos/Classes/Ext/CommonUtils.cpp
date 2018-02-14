//
//  CommonUtils.cpp
//  PatternsBundle
//
//  Created by fdp on 2018/2/14.
//
//

#include "CommonUtils.hpp"

Button *CommonUtils::createButton(const Widget::ccWidgetTouchCallback& callback,const string& normal,const string& pressed){
    string n,p;
    if (normal.empty() || pressed.empty()) {
        n = "btn_green.png";
        p = "btn_green.png";
    }
    Button *btn = Button::create(n,p);
    btn->addTouchEventListener(callback);
    return btn;
    
}

