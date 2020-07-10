#ifndef SHAPE_HPP 
#define SHAPE_HPP

//Interface
class Shape{
    public:
    //pure virtual methods - not implemented
    virtual float area() const = 0;
    virtual float volume() const = 0;
};

#endif