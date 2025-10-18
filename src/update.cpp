#include "update.h"
#include "shader.h"
#include "tempData.h"

#include <glad/glad.h>

VertexData vertexData;

Shader shader;

void start(){
 vertexData.Init();
 shader.Init("../assets/shaders/shader.vert", "../assets/shaders/shader.frag");
}

void renderUpdate(){
   glBindVertexArray(vertexData.VAO);
   shader.Use();

   glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0);
   glBindVertexArray(0);
}
