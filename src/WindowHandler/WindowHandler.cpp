#include "WindowHandler.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

WindowHandler::WindowHandler()
{
    if(!glfwInit())
    {
        logError("Failed to initialize GLFW!");
        exit(EXIT_FAILURE);
    }
    logPass("Initialized GLFW");
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window = glfwCreateWindow(WIN_W, WIN_H, "ATDE", NULL, NULL); // Arch Three Dimensional Engine
    if(window == NULL)
    {
        logError("Failed to create Window!");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    logPass("Created Window!");
    glfwMakeContextCurrent(window);
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        logError("Failed to Initialize GLAD!");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    logPass("Initialized GLAD!");

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
    if(glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    if(glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}