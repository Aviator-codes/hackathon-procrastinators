#include "config.h"
#include "WindowHandler/WindowHandler.h"
#include "shaders/shader.h"
#include "Renderer/renderer.h"

int main()
{
    WindowHandler WH = WindowHandler();
    
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    Renderer renderer = Renderer();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(renderer.FOV, (float)WH.WIN_W / (float)WH.WIN_H, 0.1f, 100.0f);

    renderer.shader.setMat4("model", model);
    renderer.shader.setMat4("view", view);
    renderer.shader.setMat4("projection", projection);

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