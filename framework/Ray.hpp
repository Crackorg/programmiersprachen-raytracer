
#ifndef RAY_HPP
#define RAY_HPP

#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
#include <iostream>

struct Ray {
    glm::vec3 origin;     
    glm::vec3 direction;  //normaliesieren (richtung)

    Ray(glm::vec3 const& orig, glm::vec3 const& dir)
        : origin(orig), direction(dir) {}   //(glm::normalize(dir)) {}

                                                           
    glm::vec3 point_at_parameter(float t) const {
        return origin + t * direction;
    }
};

#endif // RAY_HPP