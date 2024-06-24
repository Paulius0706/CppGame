#ifndef UIVertex_CPP
#define UIVertex_CPP
#include <glad/glad.h>



struct UIVertex
{
public:
    GLfloat position[3];
    //GLfloat color[4];
    GLfloat uv[2];

    static void AssignAtributes(){
        // Position attribute
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(UIVertex), (void*)offsetof(UIVertex, position));
        //// Color attribute
        //glEnableVertexAttribArray(1);
        //glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(UIVertex), (void*)offsetof(UIVertex, color));
        //// texturecord attribute
        //glEnableVertexAttribArray(2);
        //glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(UIVertex), (void*)offsetof(UIVertex, uv));

        // texturecord attribute
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(UIVertex), (void*)offsetof(UIVertex, uv));
    }
};
#endif