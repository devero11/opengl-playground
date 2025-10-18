#include <cstddef>
#include <iostream>
#include <ostream>
#include "window.h"
#include "GLFW/glfw3.h"


bool Window::Init(uint width, uint height, std::string title){
  this->width = width;
  this->height = height;
  this->title = title;
  
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window = glfwCreateWindow(this->width, this->height, this->title.c_str(), NULL, NULL);  

  if(window == NULL){
    std::cout<<"FAILED TO CREATE WINDOW"<<std::endl;
    glfwTerminate();
    return false;
  }

  glfwMakeContextCurrent(window);
  
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    std::cout << "FAILED TO INITIALIZE GLAD" << std::endl;
    return false; 
  }
  
  
  glViewport(0, 0, this->width, this->height);

  return true;
} 





void Window::Close(){
  glfwTerminate();
}





bool Window::IsOpen(){
  return !glfwWindowShouldClose(window); 
}

