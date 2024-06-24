#ifndef WindowRenderNode_CPP
#define WindowRenderNode_CPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <functional>
#include <iostream>
#include <thread>

#include "abstractRenderNode.cpp"
#include "shaderRenderNode.cpp"
    

class WindowRenderNode : public AbstractRenderNode {
public:
    static int HEIGHT;
    static int WIDTH;
    bool finished = false;
    bool loaded = false;
protected:
    GLFWwindow* window;
    std::thread thread;
    WindowRenderNode(int width, int height) : AbstractRenderNode(){
        WIDTH = width;
        HEIGHT = height;
        thread = std::thread(&windowRenderLoop,this);
    }
    void load() override{

    }    
    
    void processInput(GLFWwindow *window)
    {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }
private:
    void windowRenderLoop(){
        window = glInitialization();
        load();
        loaded = true;
        generateRenderLoops();
        glfwTerminate();
        finished = true;
    }
    void generateRenderLoops(){
        while (!glfwWindowShouldClose(window))
        {
            // input
            // -----
            processInput(window);

            // render
            // ------
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            render();


            // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
            // -------------------------------------------------------------------------------
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }


    GLFWwindow* glInitialization(){
        // glfw: initialize and configure
        // ------------------------------
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif

        // glfw window creation
        // --------------------
        GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return NULL;
        }
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, onNodeWindowResize);

        // glad: load all OpenGL function pointers
        // ---------------------------------------
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return NULL;
        }

        // configure global opengl state
        // -----------------------------
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


        glfwSwapInterval(1);
        return window;
    }
    static void onNodeWindowResize(GLFWwindow* window, int width, int height);
    
};

int WindowRenderNode::WIDTH = 0;
int WindowRenderNode::HEIGHT = 0;
void WindowRenderNode::onNodeWindowResize(GLFWwindow* window, int width, int height)
{
    WindowRenderNode::WIDTH = width;
    WindowRenderNode::HEIGHT = height;
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}



#endif