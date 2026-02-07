#include "WindowHandler.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

float lastX = WindowHandler::WIN_W/2.0f;
float lastY = WindowHandler::WIN_H/2.0f;


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
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSwapInterval(1);
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


void WindowHandler::processInput(Camera& camera, float dt)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if(glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    if(glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    if(glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
        glClearColor(0.1f, 0.3f, 0.2f, 1.0f);
    if(glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
        glClearColor(0.2f, 0.2980392f, 0.6627450980f, 1.0f);
    if(glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
        glClearColor(0.2f, 0.1f, 0.5f, 1.0f);
    const float cameraSpeed = 2.0f * dt;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.pos += cameraSpeed * camera.front;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.pos -= cameraSpeed * camera.front;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.pos -= glm::normalize(glm::cross(camera.front, camera.up)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.pos += glm::normalize(glm::cross(camera.front, camera.up)) * cameraSpeed;
    
}

double yaw = -90.0f, pitch = 0.0f;
extern Camera camera;
bool firstMouse = true;

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }


    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed: y ranges bottom to top
    lastX = xpos;
    lastY = ypos;

    const float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;
    if(pitch > 89.0f)
    pitch = 89.0f;
    if(pitch < -89.0f)
    pitch = -89.0f;
    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    camera.front = glm::normalize(direction);
}

extern float Zoom;

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    Zoom += (float)yoffset;
    if (Zoom < 20.0f)
    Zoom = 20.0f;
    if (Zoom > 90.0f)
    Zoom = 90.0f;
}