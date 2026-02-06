#include "config.h"
#include "WindowHandler/WindowHandler.h"
#include "shaders/shader.h"
#include "Renderer/renderer.h"

int main()
{
    WindowHandler WH = WindowHandler();
    
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    Renderer renderer = Renderer();

    while(!glfwWindowShouldClose(WH.get()))
    {
        WH.processInput();

        // Rendering
        renderer.draw();


        glfwSwapBuffers(WH.get());
        glfwPollEvents();
    }

    return EXIT_SUCCESS;
}