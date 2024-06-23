#ifndef GameWindow_CPP
#define GameWindow_CPP

#include <memory>
#include "gameRenderNodes/sceneShaderNode.cpp"
#include "gameRenderNodes/uiShaderNode.cpp"
#include "../core/nodes/abstractRenderNode.cpp"
#include "../core/nodes/shaderRenderNode.cpp"
#include "../core/nodes/windowRenderNode.cpp"
#include "../core/shader.cpp"

class MainWindow : public WindowRenderNode
{
public:
    SceneShaderNode sceneShaderNode;
    UIShaderNode uiShaderNode;
    MainWindow(int width, int height) : WindowRenderNode(width,height), sceneShaderNode(SceneShaderNode()), uiShaderNode(UIShaderNode()){}
    void load() override{
        //sceneShaderNode.load();
        //WindowRenderNode::AbstractRenderNode::children.push_back(&sceneShaderNode);

        uiShaderNode.load();
        WindowRenderNode::AbstractRenderNode::children.push_back(&uiShaderNode);
    }
};





#endif