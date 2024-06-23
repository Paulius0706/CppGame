#version 330 core

uniform vec2 WindowSize;
uniform vec2 TextureSize;

uniform vec4 PositionSize;
uniform vec4 UVPositionSize;

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aUV;
  
out vec4 vColor;
out vec2 vUV;

void main()
{
    gl_Position = vec2(
        PositionSize.x/WindowSize.x + aPosition.x*PositionSize.z/WindowSize.x, 
        PositionSize.y/WindowSize.y + aPosition.y*PositionSize.w/WindowSize.y);
    vUV = vec2(
        UVPositionSize.x/TextureSize.x + aUV.x*UVPositionSize.z/TextureSize.x, 
        UVPositionSize.y/TextureSize.y + aUV.y*UVPositionSize.w/TextureSize.y);
    vColor = aColor;

}  