#include <iostream>
#include "window.h"


int Window::createWIndow(int width, int height, const char* title, GLFWwindow*& window){
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); 
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window = glfwCreateWindow(width, height, title, NULL, NULL);
  if(window == NULL){
    std::cout << "Failed to initialize GLFW" << std::endl;
    glfwTerminate();
    return -1;
  } 

  glfwMakeContextCurrent(window);
  
  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    std::cout<< "Failed To initialize GLAD" << std::endl;
    return -1;
  }

  glViewport(0,0, width,height);


  return 0;

}
  
