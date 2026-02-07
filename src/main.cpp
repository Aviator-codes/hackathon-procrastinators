#include "config.h"
#include "WindowHandler/WindowHandler.h"
#include "shaders/shader.h"
#include "Renderer/renderer.h"

int main()
{
    WindowHandler WH = WindowHandler();
    
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    Renderer renderer = Renderer();

    glm::mat4 model = glm::rotate(glm::mat4(1.0f), 0.009f * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));    
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(renderer.FOV, (float)WH.WIN_W / (float)WH.WIN_H, 0.1f, 100.0f);
    renderer.shader.setMat4("model", model);
    renderer.shader.setMat4("view", view);
    renderer.shader.setMat4("projection", projection);

    glm::vec3 cubePositions[] = {       // random values
        glm::vec3( 0.0f, 0.0f, 0.0f),
        glm::vec3( 2.0f, 5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f, 3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f, 2.0f, -2.5f),
        glm::vec3( 1.5f, 0.2f, -1.5f),
        glm::vec3(-1.3f, 1.0f, -1.5f)
    };
    
    float last_time = glfwGetTime();
    float dt = glfwGetTime() - last_time;

    while(!glfwWindowShouldClose(WH.get()))
    {
        float current_time = glfwGetTime();
        float dt = current_time - last_time;
        last_time = current_time;


        model = glm::rotate(model, dt * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
        renderer.shader.setMat4("model", model);
        WH.processInput();

        // Rendering
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        renderer.draw(cubePositions);


        glfwSwapBuffers(WH.get());
        glfwPollEvents();
        dt = glm::min(dt, 0.033f);
    }

    return EXIT_SUCCESS;
}