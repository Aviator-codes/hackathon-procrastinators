#include "config.h"
#include "WindowHandler/WindowHandler.h"
#include "shaders/shader.h"

int main()
{
    WindowHandler WH = WindowHandler();
    
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    float vertices[] = 
    {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    Shader shader = Shader("../src/shaders/shader.vert", "../src/shaders/shader.frag");
    
    uint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    uint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    shader.use();

    while(!glfwWindowShouldClose(WH.get()))
    {
        WH.processInput();

        
        // Rendering
        glClear(GL_COLOR_BUFFER_BIT);
        shader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        

        glfwSwapBuffers(WH.get());
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    return EXIT_SUCCESS;
}