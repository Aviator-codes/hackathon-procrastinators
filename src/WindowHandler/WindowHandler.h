#pragma once
#include "../config.h"

// Handling Window and GLFW and GLAD inits
class WindowHandler
{
private:
    GLFWwindow* window = NULL;
    static constexpr int WIN_W = 800, WIN_H = 600;
public:
    WindowHandler();
    ~WindowHandler();
    void processInput();
    GLFWwindow* get() const;
};