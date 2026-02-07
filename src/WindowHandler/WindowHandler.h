#pragma once
#include "../config.h"
#include "../camera/camera.h"

// Handling Window and GLFW and GLAD inits
struct WindowHandler
{
    GLFWwindow* window = NULL;
    static constexpr int WIN_W = 800, WIN_H = 600;

    WindowHandler();
    ~WindowHandler();
    void processInput(Camera& camera, float dt);
    GLFWwindow* get() const;
};