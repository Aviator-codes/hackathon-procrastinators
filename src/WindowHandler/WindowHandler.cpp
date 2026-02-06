#include "WindowHandler.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

WindowHandler::WindowHandler()
{
    if(!glfwInit())
    {
        printf("[ERROR]: Failed to initialize GLFW!\n");
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(WIN_W, WIN_H, "ATDE", NULL, NULL); // Arch Three Dimensional Engine
    if(window == NULL)
    {
        printf("[ERROR]: Failed to create Window!\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("[ERROR]: Failed to initialise glad!\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glViewport(0, 0, WIN_W, WIN_H);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

WindowHandler::~WindowHandler()
{
    glfwTerminate();
}

GLFWwindow *WindowHandler::get() const
{
    return window;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}



void WindowHandler::processInput()
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}