#pragma once
#include "../config.h"

struct Camera
{
    const glm::vec3 global_up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 up, right, front;
    glm::vec3 pos;

    Camera();
    void update();
    glm::mat4 getView() const;
};