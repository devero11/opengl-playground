#pragma once

#include <string>
#include <sys/types.h>
#include <fstream>

class Shader{
  public:
    uint ID; 
  
    void Init(const char* vertexPath, const char* fragmentPath);

    void Use();
    void SetBool(const std::string &name, bool value) const;
    void SetInt(const std::string &name, int value) const ;
    void SetFloat(const std::string &name, float value) const;

};


extern Shader (&shaderList)[10];
