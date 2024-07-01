#include "Sphere.hpp"
#include <numbers>
#include <cmath>

Sphere::Sphere(glm::vec3 const& m, float r, std::string const& name, Color const& farbe) : Shape{name, farbe}, mitte_(m), radius_(r) {

}
float Sphere::area() const {
	//4*r*pi^2
	float oberfläche = 4.0f * radius_ * pow(3.1415f, 2) ;
	return oberfläche;
}

float Sphere::volume() const {
	//4/3*pi*r^3
	float volumen_ = (4.0 / 3.0) * 3.1415f * pow(radius_, 3);

	return volumen_;
}
std::ostream& Sphere::print(std::ostream& os) const {
	Shape::print(os); 
	os << ", Mitte: " << mitte_.y << ", " << mitte_.x << ", " << mitte_.z << ", " << " Radius: " << radius_ << std::endl;
	return os;
}
HitPoint Sphere::intersect(Ray const& ray) const {
    float distance;
    glm::vec3 normalized_direction = glm::normalize(ray.direction); 

    
    bool intersected = glm::intersectRaySphere( //distance param. wird nach aufruf dieser funktion überschrieben 
        ray.origin, normalized_direction,
        mitte_, radius_ * radius_,
        distance
    );

    HitPoint hit_point;
    hit_point.intersected = intersected;
    hit_point.distance = distance;
    hit_point.object_name = name_;
    hit_point.object_color = farbe_;

    if (intersected) {
        // schnittpunkt 
        hit_point.intersection_point = ray.origin + distance * normalized_direction;
        hit_point.intersection_direction = normalized_direction;
    }

    return hit_point;
}
Sphere::~Sphere() {
    std::cout << name_ << " destroyed" << std::endl;
}