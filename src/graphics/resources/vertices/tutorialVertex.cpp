#ifndef TutorialVertex_CPP
#define TutorialVertex_CPP
#include <glad/glad.h>



struct TutorialVertex
{
public:
    GLfloat position[3];
    GLfloat color[3];
    //GLfloat texCoord[2];

    static void AssignAtributes(){
        // Position attribute
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(TutorialVertex), (void*)offsetof(TutorialVertex, position));
        // Color attribute
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(TutorialVertex), (void*)offsetof(TutorialVertex, color));
    }
};
#endif