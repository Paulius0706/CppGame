#ifndef UniformObject_CPP
#define UniformObject_CPP

#include <glad/glad.h>

#include "abstractRenderNode.cpp"

class UniformObject
{
public:
    bool visible;

    UniformObject() : visible(true){
        
    }
    virtual void loadUniforms(){

    }
};
#endif