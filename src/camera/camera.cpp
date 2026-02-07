#include "camera.h"

Camera::Camera()
{
    pos   = glm::vec3(0.0f, 0.0f, 3.0f);
    front = glm::vec3(0.0f, 0.0f, -1.0f);
    up    = glm::vec3(0.0f, 1.0f, 0.0f);
}

void Camera::update()
{
    //pos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraDirection = glm::normalize(pos - cameraTarget);
    right = glm::normalize(glm::cross(up, cameraDirection));
    up    = glm::cross(cameraDirection, right);
}

glm::mat4 Camera::getView() const
{
    return glm::lookAt(pos, pos + front, up);
}
