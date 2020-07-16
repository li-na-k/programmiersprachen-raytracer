#ifndef SHAPE_HPP 
#define SHAPE_HPP

#include <string>
#include <iostream>
#include "color.hpp"
#include "ray.hpp"

//Interface
class Shape{
    public:
    //Konstruktoren 
    Shape();
    Shape(std::string const& n, Color const& c);

    //Destruktor (virtuell)
    virtual ~Shape();

    //pure virtual methods - not implemented
    virtual float area() const = 0;
    virtual float volume() const = 0;

    //virtual
    virtual std::ostream& print(std::ostream& os) const;

    protected:
        std::string name_;
        Color color_; //r, g, b
};

std::ostream& operator <<(std::ostream& os, Shape const& s);

#endif