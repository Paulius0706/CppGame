#ifndef UIShaderNode_CPP
#define UIShaderNode_CPP

#include <glad/glad.h>
#include "../../core/nodes/windowRenderNode.cpp"
#include "../../core/nodes/shaderRenderNode.cpp"
#include "../../core/nodes/layoutRenderNode.cpp"
#include "../../core/shader.cpp"
#include "../../core/texture.cpp"
#include "../vertices/tutorialVertex.cpp"
#include "../vertices/uiVertex.cpp"

class QuadLayoutNode : public LayoutRenderNode<UIVertex>
{
public:
    Layout<UIVertex> triangle;
    QuadLayoutNode() : LayoutRenderNode(), triangle(Layout<UIVertex>()){};
    void load() override{
        triangle.load(
            UIVertex::AssignAtributes
            ,new UIVertex[4]{
                // positions         // colors
                {{ 1.0f,  1.0f, 0.0f},  /*{1.0f, 0.0f, 0.0f, 1.0f},*/ {1.0f, 1.0f}},  
                {{ 1.0f,  0.0f, 0.0f},  /*{0.0f, 1.0f, 0.0f, 1.0f},*/ {1.0f, 0.0f}},  
                {{ 0.0f,  0.0f, 0.0f},  /*{0.0f, 0.0f, 1.0f, 1.0f},*/ {0.0f, 0.0f}},  
                {{ 0.0f,  1.0f, 0.0f},  /*{0.0f, 0.0f, 1.0f, 1.0f},*/ {0.0f, 1.0f}} 
            }
            ,4
            ,new int[6] {3, 0, 1, 2, 1, 3}
            ,6);
        LayoutRenderNode::layout = &triangle;
    }
};
//  3    0
//      
//  2    1

class UIShaderNode : public ShaderRenderNode
{
private:
    /* data */
public:
    Shader uiShader;
    Texture texture;
    QuadLayoutNode quadLayoutNode;
    UIShaderNode() : ShaderRenderNode(), uiShader(Shader()), quadLayoutNode(QuadLayoutNode()){}
    void load() override{
        uiShader.load(".\\Shaders\\UserInterfaceShader\\vertex.vs", ".\\Shaders\\UserInterfaceShader\\fragment.vs");
        ShaderRenderNode::shader = &uiShader;
        
        texture.load(".\\Textures\\CONSOLA.png");
        //texture.load(".\\Textures\\Fonts\\ComicSansMSAlpha.png");

        quadLayoutNode.load();
        ShaderRenderNode::AbstractRenderNode::children.push_back(&quadLayoutNode);
    }
    void loadStaticUniforms() override{
        texture.use();
        uiShader.setVec2("WindowSize", glm::vec2(WindowRenderNode::WIDTH,WindowRenderNode::HEIGHT));
        uiShader.setVec2("TextureSize", glm::vec2(texture.width,texture.height));
        
        //uniform vec2 WindowSize;
        //uniform vec2 TextureSize;

        //uniform vec4 PositionSize;
        //uniform vec4 UVPositionSize;
    }
};
#endif