#ifndef SPHERE_HPP 
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"
#include <string>
#include "hitpoint.hpp"
#include "ray.hpp"

class Sphere : public Shape{
    public:
        //Konstruktoren
        Sphere();
        Sphere(glm::vec3 const& cntr, float const& r);
        Sphere(glm::vec3 const& cntr, float const& r, std::string const& n, Color const& c);
        //Destruktor
        ~Sphere();
        /* virtual */ float area() const override;
        /* virtual */ float volume() const override;
        /* virtual */ std::ostream& print(std::ostream& os) const override;
        HitPoint intersect(Ray r, float t) const;

    private:
        glm::vec3 center_;
        float radius_;
};

#endif