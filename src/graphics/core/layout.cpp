#ifndef AbstractLayout_CPP
#define AbstractLayout_CPP

#include <glad/glad.h>
#include <functional>
#include <stdexcept>


template <class T>
class Layout
{
    public:
        Layout(){}
        void load(void (*assignAtributesFunc)(),  T* vertices, size_t vertexCount,  int* indices = nullptr, size_t indexCount = 0){
            //if(vertex_Count = 0 || assignAtributesFunc == nullptr || vertices == nullptr){
            //    return;
            //}
            vertex_Count = vertexCount;
            indices_Count = indexCount;
            generateBuffers(indices);
            //assign array
            glBindVertexArray(VAO_ptr);

            loadBuffer(vertices,vertexCount);

            if (indices) {
                loadIndices(indices, indexCount);
            }

            assignAtributes(assignAtributesFunc);            

            //unassign array
            glBindVertexArray(0);
        }
        void useRenderUnuse() {
            use();
            render();
            unuse();
        }
        void render(){
            if (EBO_ptr) {
                glDrawElements(GL_TRIANGLES, vertex_Count, GL_UNSIGNED_INT, 0);
            } else {
                glDrawArrays(GL_TRIANGLES, 0, vertex_Count);
            }
        }
        void use(){
            glBindVertexArray(VAO_ptr);
        }
        void unuse(){
            glBindVertexArray(0);
        }
    protected:
        GLuint VAO_ptr;
        GLuint VBO_ptr;
        GLuint EBO_ptr;
        int vertex_Count = 0;
        int indices_Count = 0;
        void assignAtributes(void (*assignAtributesFunc)()){
            assignAtributesFunc();
        }
    private:
        void generateBuffers(bool includeIndices){
            glGenVertexArrays(1, &VAO_ptr);
            glGenBuffers(1, &VBO_ptr);
            if (includeIndices) {
                glGenBuffers(1, &EBO_ptr);
            }
        }
        void loadBuffer( T* vertices, size_t vertexCount){
            glBindBuffer(GL_ARRAY_BUFFER, VBO_ptr);
            glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(T), vertices, GL_STATIC_DRAW);
        }
        void loadIndices( int* indices = nullptr, size_t indexCount = 0){
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_ptr);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);
        }
        
};
#endif