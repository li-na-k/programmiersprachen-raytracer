#ifndef SPHERE_HPP 
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"
#include <string>

class Sphere : public Shape{
    public:
        //Konstruktoren
        Sphere();
        Sphere(glm::vec3 cntr, float r);
        Sphere(glm::vec3 cntr, float r, std::string n, Color c);
        /* virtual */ float area() const override;
        /* virtual */ float volume() const override;
    private:
        glm::vec3 center_;
        float radius_;
};

#endif