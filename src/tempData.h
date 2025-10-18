#pragma once

#include <sys/types.h>
#include <glad/glad.h>

class VertexData{
  public:
    uint VAO,VBO,EBO;
    
    const float VERTICES[24] = {
      -0.5f, -0.5f, 0, 1,0,0,
       0.5f, -0.5f, 0, 0,1,0,
      -0.5f,  0.5f, 0, 0,0,1,
       0.5f,  0.5f, 0, 1,0,1
    };

    const int INDICES[6]= {
     0,1,2,1,2,3 
    };
    const float texCoords[6] = {
        0.0f, 0.0f,  // lower-left corner  
        1.0f, 0.0f,  // lower-right corner
        0.5f, 1.0f   // top-center corner
    };
    void Init();
};
