#ifndef BOX_HPP 
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"
#include <iostream>

class Box : public Shape{
    public:
        //Konstruktoren
        Box();
        Box(glm::vec3 const& min, glm::vec3 const& max);
        Box(glm::vec3 const& min, glm::vec3 const& max, std::string const& n, Color const& c);
        //Destruktor
        ~Box();
        //TODO: test that min < max ?
        /* virtual */ float area() const override;
        /* virtual */ float volume() const override;
        std::ostream& print(std::ostream& os) const override;

    private:
        glm::vec3 min_;
        glm::vec3 max_;
};

#endif