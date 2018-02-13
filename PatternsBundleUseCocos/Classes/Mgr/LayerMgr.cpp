#include "LayerMgr.h"
#include "CommonInclude.h"
#include "MainScene.h"

static LayerMgr *_instance = nullptr;

LayerMgr* LayerMgr::getInstance(){
    if (!_instance) {
        _instance = new LayerMgr();
    }
    return _instance;
}

void LayerMgr::initScene(){
    _mainScene = MainScene::create();
    Director::getInstance()->runWithScene(_mainScene);

}
