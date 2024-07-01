#ifndef HIT_POINT_HPP
#define HIT_POINT_HPP

#include <string>
#include <glm/vec3.hpp>
#include "color.hpp"


struct HitPoint {
    bool intersected;           // Ob ein Schnitt stattgefunden hat
    float distance;             // Entfernung vom Ray-Startpunkt zum Schnittpunkt
    std::string object_name;    // Name des geschnittenen Objekts
    Color object_color;         // Farbe des geschnittenen Objekts
    glm::vec3 intersection_point; // 3D-Koordinate des Schnittpunkts
    glm::vec3 intersection_direction; // Richtung, mit der der Strahl das Objekt geschnitten hat
};

#endif