#ifndef BOX_HPP 
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"

class Box : public Shape{
    public:
        //Konstruktoren
        Box();
        Box(glm::vec3 min, glm::vec3 max);
        //TODO: test that min < max ?
        /* virtual */ float area() const override;
        /* virtual */ float volume() const override;
    private:
        glm::vec3 min_;
        glm::vec3 max_;
};

#endif