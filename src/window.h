#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window{
  public:
    const int WINDOW_WIDTH = 420;
    const int WINDOW_HEIGHT = 360;
    GLFWwindow* window;
    int createWIndow(int width, int height, const char* title, GLFWwindow*& window);
};

