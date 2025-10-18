#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <sys/types.h>

#include "update.h"
#include "shader.h"
#include "window.h" 

Window window;

const uint WIDTH = 1260;
const uint HEIGHT = 720;

int main(){
  if(!window.Init(WIDTH, HEIGHT, "Title"))  return -1;
 
  start();
  while (window.IsOpen()) {
    
    renderUpdate();

    glfwSwapBuffers(window.window);
    glfwPollEvents();
  }

  window.Close();
}



