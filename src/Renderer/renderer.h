#pragma once
#include "../config.h"
#include "../WindowHandler/WindowHandler.h"
#include "../shaders/shader.h"

class Renderer
{
private:
    Shader shader;
    uint VAO, VBO, EBO;
    uint vertexCount;
    
public:
    Renderer();
    ~Renderer();
    void draw();
};