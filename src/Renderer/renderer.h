#pragma once
#include "../config.h"
#include "../WindowHandler/WindowHandler.h"
#include "../shaders/shader.h"
#include "../stb_image/stb_image.h"

struct Renderer
{
    uint VAO, VBO, EBO, Texture;
    uint vertexCount;

    float FOV = 70.0f;

    Shader shader;
    Renderer();
    ~Renderer();
    void draw(glm::vec3 positions[10]);
    void loadTexture(const char* TexFilePath);
};