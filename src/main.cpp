#include "config.h"
#include "WindowHandler/WindowHandler.h"
#include "shaders/shader.h"

int main()
{
    WindowHandler WH = WindowHandler();
    
    glClearColor(0.1f, 0.1f, 0.4f, 1.0f);

    float vertices[] = 
    {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    uint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
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