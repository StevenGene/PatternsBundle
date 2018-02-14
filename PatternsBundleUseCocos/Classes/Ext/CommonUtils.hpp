//
//  CommonUtils.hpp
//  PatternsBundle
//
//  Created by fdp on 2018/2/14.
//
//

#ifndef CommonUtils_hpp
#define CommonUtils_hpp

#include "CommonInclude.h"
namespace CommonUtils {
    
    Button *createButton(const Widget::ccWidgetTouchCallback& callback,const string& normal = "",const string& pressed = "");
}
#endif /* CommonUtils_hpp */
