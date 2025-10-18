#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <sys/types.h>
#include <string>

class Window{
  public:
    uint width;
    uint height;
    std::string title;
    GLFWwindow* window;

    
    void Close();
    void Resize(uint width, uint height);


    bool Init(uint width, uint height, std::string title);
    bool IsOpen();
};

