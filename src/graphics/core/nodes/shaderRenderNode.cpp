#ifndef ShaderRenderNode_CPP
#define ShaderRenderNode_CPP


#include <glad/glad.h>

#include "abstractRenderNode.cpp"
#include "../shader.cpp"

class ShaderRenderNode : public  AbstractRenderNode
{
private:
    
    /* data */
protected:
    Shader* shader;
    ShaderRenderNode() : AbstractRenderNode(){}
    
    void render() override{
        shader->use();
        loadStaticUniforms();
        AbstractRenderNode::render();
        shader->un_use();
    }
    virtual void loadStaticUniforms(){
        
    }
    void load() override{
        
    }
};


#endif