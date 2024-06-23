#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <thread>
#include "graphics/resources/vertices/tutorialVertex.cpp"

#include "graphics/resources/mainWindow.cpp"
#include "graphics/resources/uniformObjects/uiBoxUniformObject.cpp"


MainWindow* mainWindow;

int main(int argc, char * argv[])
{
    mainWindow = new MainWindow(800,600);
    
    std::this_thread::sleep_for(std::chrono::seconds(4));
    while (!mainWindow->loaded){}
    std::cout << "Windows loaded" <<std::endl;
    UIBoxUniformObject uniformObject1 = UIBoxUniformObject(mainWindow, glm::vec2(100,100),glm::vec2(100,100),glm::vec2(0,0),glm::vec2(100,100));
    mainWindow->uiShaderNode.quadLayoutNode.addUniformObject(&uniformObject1);
    while (!mainWindow->finished)
    {
        std::this_thread::sleep_for(std::chrono::seconds(4));
    }
    
    return 0;
}



