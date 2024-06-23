#ifndef UIBoxUniformObject_CPP
#define UIBoxUniformObject_CPP

#include <glm/glm.hpp>
#include <glad/glad.h>


#include "../../core/uniformObject.cpp"

class UIBoxUniformObject : UniformObject
{
    glm::vec2 position;
    glm::vec2 size;
    glm::vec2 texturePosition;
    glm::vec2 textureSize;
public:
    UIBoxUniformObject(glm::vec2 position, glm::vec2 size, glm::vec2 texturePosition, glm::vec2 textureSize) : UniformObject(), 
        position(position),
        size(size),
        texturePosition(texturePosition),
        textureSize(textureSize)  {
        
    }
    
    void loadUniforms() override{
        UniformObject::shader->setVec4("PositionSize", glm::vec4(position.x,position.y,size.x,size.y));
        UniformObject::shader->setVec2("UVPositionSize", glm::vec4(texturePosition.x,texturePosition.y, textureSize.x, textureSize.y));
    }   
};
#endif