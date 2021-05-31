#pragma once
#include "MyObject.h"

#include<memory>
class MyCube :
    public MyObject
{
public:
    MyCube() : MyCube(1.0f) {};

    MyCube(float);
    MyCube(const MyCube&) = default;
    MyCube(MyCube&&) = default;
    MyCube& operator=(const MyCube&) = default;
    MyCube& operator=(MyCube&&) = default;
};

