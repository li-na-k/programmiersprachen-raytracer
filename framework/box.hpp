#ifndef BOX_HPP 
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"

class Box : public Shape{
    public:
        //Konstruktoren
        Box();
        Box(glm::vec3 min, glm::vec3 max);
        Box(glm::vec3 min, glm::vec3 max, std::string n, Color c);
        //TODO: test that min < max ?
        /* virtual */ float area() const override;
        /* virtual */ float volume() const override;
    private:
        glm::vec3 min_;
        glm::vec3 max_;
};

#endif