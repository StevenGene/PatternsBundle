#include "MainScene.h"
#include "MainLayer.h"

bool MainScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    this->addChild(MainLayer::create());
    return true;
}
