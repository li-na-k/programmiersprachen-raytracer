#include "shape.hpp"
#include <iostream>

std::ostream& Shape::print(std::ostream& os) const {
    os << "Name: " << name_ << std::endl;
    os << "Color: " << color_.r << ", " << color_.g << ", " << color_.b << std::endl;
    return os;
}

Shape::Shape(std::string n, Color c){
        name_ = n;
        color_ = c;
    }

Shape::Shape(){
        name_ = "beispielname";
        color_ = Color{1.0, 1.0, 1.0};
    }

std::ostream& operator <<(std::ostream& os, Shape const& s) {
    return s.print(os);
}