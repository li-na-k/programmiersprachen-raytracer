#include "sphere.hpp"
#include <math.h>
#include <glm/vec3.hpp>
#include <string>

Sphere::Sphere():
    center_ {0.0f, 0.0f, 0.0f},
    radius_ {100.0f}
{}

Sphere::Sphere(glm::vec3 cntr, float r):
    Shape(),
    center_ {cntr},
    radius_ {r}
{}

Sphere::Sphere(glm::vec3 cntr, float r, std::string n, glm::vec3 c):
    Shape(n, c),
    center_ {cntr},
    radius_ {r}
{}

//surface area of sphere: 4*pi*r^2
float Sphere::area() const{
    return 4 * M_PI * pow(radius_, 2);
}

//volume of sphere: 4/3 πr³
float Sphere::volume() const{
    return 4.0f/3.0f * M_PI * pow(radius_,3);
}