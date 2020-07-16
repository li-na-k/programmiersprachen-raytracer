#include "sphere.hpp"
#include <math.h>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>


Sphere::Sphere():
    Shape(),
    center_ {0.0f, 0.0f, 0.0f},
    radius_ {100.0f}
{std::cout << "Konstrukor Sphere " << name_ << " aufgerufen \n";}

Sphere::Sphere(glm::vec3 const& cntr, float const& r):
    Shape(),
    center_ {cntr},
    radius_ {r}
{std::cout << "Konstrukor Sphere " << name_ << " aufgerufen \n";}

Sphere::Sphere(glm::vec3 const& cntr, float const& r, std::string const& n, Color const& c):
    Shape(n, c),
    center_ {cntr},
    radius_ {r}
{std::cout << "Konstrukor Sphere " << name_ << " aufgerufen \n";}

Sphere::~Sphere() {
    std::cout << "Destruktor Sphere " << name_ << " aufgerufen \n";
}

//surface area of sphere: 4*pi*r^2
float Sphere::area() const{
    return 4 * M_PI * pow(radius_, 2);
}

//volume of sphere: 4/3 πr³
float Sphere::volume() const{
    return 4.0f/3.0f * M_PI * pow(radius_,3);
}

//override print method
std::ostream& Sphere::print(std::ostream& os) const {
    Shape::print(os);
    os << "Center: " << center_.x << ", " << center_.y << ", " << center_.z << std::endl;
    os << "Radius: " << radius_ << std::endl;
    return os;
}

/*
bool 	intersectRaySphere (genType const &rayStarting, genType const &rayNormalizedDirection, 
genType const &sphereCenter, typename genType::value_type const sphereRadiusSquered, 
typename genType::value_type &intersectionDistance)*/

HitPoint Sphere::intersect(Ray r, float t) const{
    bool result = glm::intersectRaySphere(
                r.origin, glm::normalize(r.direction),
                center_, pow(radius_,2), t);
    return HitPoint{result, t, name_, color_, r.origin + t * r.direction, r.direction};
}
