#ifndef SHAPE_HPP 
#define SHAPE_HPP

#include <string>
#include <iostream>
#include "color.hpp"

//Interface
class Shape{
    public:
    //Konstruktoren 
    Shape(){
        name_ = "beispielname";
        color_ = Color{1.0, 1.0, 1.0};
    }

    Shape(std::string n, Color c){
        name_ = n;
        color_ = c;
    }

    //pure virtual methods - not implemented
    virtual float area() const = 0;
    virtual float volume() const = 0;

    //virtual
    std::ostream& print(std::ostream& os) const;

    protected:
        std::string name_;
        Color color_; //r, g, b
};

std::ostream& operator <<(std::ostream& os, Shape const& s);

#endif