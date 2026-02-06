#include "config.h"
#include "WindowHandler/WindowHandler.h"


int main()
{
    WindowHandler WH = WindowHandler();
    
    glClearColor(0.2f, 0.2980392f, 0.6627450980f, 1.0f);
    
    while(!glfwWindowShouldClose(WH.get()))
    {
        WH.processInput();
        
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(WH.get());
        glfwPollEvents();
    }


    WH.~WindowHandler();
    return EXIT_SUCCESS;
}