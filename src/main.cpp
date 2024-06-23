#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <thread>
#include "graphics/resources/vertices/tutorialVertex.cpp"

#include "graphics/resources/mainWindow.cpp"


UniformObject* uniformObject; 
MainWindow* mainWindow;

int main()
{

    mainWindow = new MainWindow();
    
    std::this_thread::sleep_for(std::chrono::seconds(4));
    UniformObject uniformObject1 = UniformObject();
    while (!mainWindow->loaded){}
    mainWindow ->sceneShaderNode.triangleLayoutNode.addUniformObject(uniformObject1);
    while (!mainWindow->finished)
    {
        std::this_thread::sleep_for(std::chrono::seconds(4));
    }
    
    return 0;
}



