#include "box.hpp"
#include <math.h>

Box::Box():
    min_ {0.0f, 0.0f, 0.0f},
    max_ {100.0f, 100.0f, 100.0f}
{}

Box::Box(glm::vec3 min, glm::vec3 max):
    min_ {min},
    max_ {max}
{}

//3d box area: 6 * s^2
float Box::area() const{
    //legth of sides
    float l = max_.x - min_.x;
    float b = max_.y - min_.y;
    float h = max_.z - min_.z;
    return (2*l*h)+(2*h*b)+(2*l*b);
}

//3D box volume: l*b*h
float Box::volume() const{
    //length of sides
    float l = max_.x - min_.x;
    float b = max_.y - min_.y;
    float h = max_.z - min_.z;
    return l*b*h;
}
