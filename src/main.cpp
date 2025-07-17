#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window.h" 
#include "update.h"
#include "triangle.h" 
#include "shaders.h"
#include "buffers.h" 

Window window;
Triangle triangle; 
Buffers buffers;



int main(){

  window.createWIndow(window.WINDOW_WIDTH, window.WINDOW_HEIGHT, "Project Title", window.window); 
  
  buffers.init();
  buffers.bindBuffers(triangle.VERTICES, triangle.INDICES, sizeof(triangle.VERTICES), sizeof(triangle.INDICES)); 

  createProgram(triangle.vertexShader, triangle.fragmentShader, triangle.VERTEX_SHADER_CODE, triangle.FRAGMENT_SHADER_CODE, triangle.shaderProgram);


  int vertexTimeLocation = glGetUniformLocation(triangle.shaderProgram,"time");

  while (!glfwWindowShouldClose(window.window)) {

    glUniform1f(vertexTimeLocation,glfwGetTime());
    renderUpdate( triangle.shaderProgram, buffers.VBO);
    glfwSwapBuffers(window.window);
    glfwPollEvents();    
  }

  glfwTerminate();

  return 0;
}



