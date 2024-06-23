#ifndef sceneShaderNode_CPP
#define sceneShaderNode_CPP

#include "../../core/nodes/shaderRenderNode.cpp"
#include "../../core/nodes/layoutRenderNode.cpp"
#include "../../core/shader.cpp"
#include "../vertices/tutorialVertex.cpp"



class TriangleLayoutNode : public LayoutRenderNode<TutorialVertex>
{
public:
    Layout<TutorialVertex> triangle;
    TriangleLayoutNode() : LayoutRenderNode(), triangle(Layout<TutorialVertex>()){};
    void load() override{
        triangle.load(
            TutorialVertex::AssignAtributes
            ,new TutorialVertex[3]{
                // positions         // colors
                {{0.5f, -0.5f, 0.0f},  {1.0f, 0.0f, 0.0f}},  // bottom right
                {{-0.5f, -0.5f, 0.0f},  {0.0f, 1.0f, 0.0f}},  // bottom left
                {{0.0f,  0.5f, 0.0f},  {0.0f, 0.0f, 1.0f}}   // top 
            }
            ,3
            ,new int[3] {0, 1, 2}
            ,3);
        LayoutRenderNode::layout = &triangle;
    }
};


class SceneShaderNode : public ShaderRenderNode
{
private:
    /* data */
public:
    Shader sceneShader;
    TriangleLayoutNode triangleLayoutNode; 
    SceneShaderNode() : ShaderRenderNode(), sceneShader(Shader()), triangleLayoutNode(TriangleLayoutNode()){}
    void load() override{
        sceneShader.load(".\\Shaders\\MainShader\\vertex.vs", ".\\Shaders\\MainShader\\fragment.fs");
        ShaderRenderNode::shader = &sceneShader;
        triangleLayoutNode.load();
        ShaderRenderNode::AbstractRenderNode::children.push_back(&triangleLayoutNode);
    }
    void loadStaticUniforms() override{

    }
};


#endif