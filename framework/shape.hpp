#ifndef SHAPE_HPP 
#define SHAPE_HPP

#include <string>

//Interface
class Shape{
    public:
    //pure virtual methods - not implemented
    virtual float area() const = 0;
    virtual float volume() const = 0;

    Shape(){
        name_ = "beispielname";
        color_ = glm::vec3{1.0, 1.0, 1.0};
    }

    Shape(std::string n, glm::vec3 c){
        name_ = n;
        color_ = c;
    }

    protected:
        std::string name_;
        glm::vec3 color_; //r, g, b
};

#endif