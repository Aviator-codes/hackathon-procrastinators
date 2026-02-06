#pragma once
#include "../config.h"
#include "../WindowHandler/WindowHandler.h"
#include "../shaders/shader.h"
#include "../stb_image/stb_image.h"

class Renderer
{
private:
    Shader shader;
    uint VAO, VBO, EBO, Texture;
    uint vertexCount;
    
public:
    Renderer();
    ~Renderer();
    void draw();
    void loadTexture(const char* TexFilePath);
};