#pragma once
#include "MyObject.h"
#include<string>
class OBJObject :
    public MyObject
{
public:
    OBJObject(std::string, std::string,bool = false);
    OBJObject();
    OBJObject(const OBJObject&) = default;
    OBJObject(OBJObject&&) = default;
    OBJObject& operator=(const OBJObject&) = default;
    OBJObject& operator=(OBJObject&&) = default;
};

