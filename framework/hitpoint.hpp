#ifndef HIT_POINT_HPP
#define HIT_POINT_HPP

#include <glm/vec3.hpp>
#include <string>

struct HitPoint {
    bool intersection_done = false;
    float t = 0.0f;
    std::string name = "";
    Color color {0.0f, 0.0f, 0.0f};
    glm::vec3 intersection_point = {0.0f, 0.0f, 0.0f};
    glm::vec3 direction = {0.0f, 0.0f, 0.0f};
};

#endif 