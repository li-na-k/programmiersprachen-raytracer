#include "box.hpp"
#include <math.h>
#include <iostream>

Box::Box():
    Shape(),
    min_ {0.0f, 0.0f, 0.0f},
    max_ {100.0f, 100.0f, 100.0f}
{std::cout << "Konstrukor Box aufgerufen \n";}

Box::Box(glm::vec3 const& min, glm::vec3 const& max):
    Shape(),
    min_ {min},
    max_ {max}
{std::cout << "Konstrukor Box aufgerufen \n";}

Box::Box(glm::vec3 const& min, glm::vec3 const& max, std::string const& n, Color const& c):
    Shape(n, c),
    min_ {min},
    max_ {max}
{std::cout << "Konstrukor Box aufgerufen \n";}

Box::~Box() {
    std::cout << "Destruktor Box aufgerufen \n";
}

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

//override print
std::ostream& Box::print(std::ostream& os) const {
    Shape::print(os);
    os << "Minimum: " << min_.x << ", " << min_.y << ", " << min_.z << std::endl;
    os << "Maximum: " << max_.x << ", " << max_.y << ", " << max_.z << std::endl;
    return os;
}
