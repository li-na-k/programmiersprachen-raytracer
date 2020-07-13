#include "shape.hpp"

std::ostream& Shape::print(std::ostream& os) const {
    os << "Name: " << name_ << std::endl;
    os << "Color: " << color_.r << ", " << color_.g << ", " << color_.b << std::endl;
    return os;
}

std::ostream& operator <<(std::ostream& os, Shape const& s) {
    return s.print(os);
}