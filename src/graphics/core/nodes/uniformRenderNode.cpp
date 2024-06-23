#ifndef UniformRenderNode_CPP
#define UniformRenderNode_CPP

#include <glad/glad.h>

#include "abstractRenderNode.cpp"

template <class T>
class UniformRenderNode : public  AbstractRenderNode
{
private:
    void render() override{
        loadStaticUniforms();
        AbstractRenderNode::render();
    }
protected:
    UniformRenderNode() : AbstractRenderNode(){
        
    }
    
    void loadStaticUniforms(){
        
    }
    void load() override{

    }
};
#endif