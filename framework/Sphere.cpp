#include "Sphere.hpp"
#include <numbers>
#include <cmath>

Sphere::Sphere(glm::vec3 const& m, float r) : Shape(), mitte_(m), radius_(r) {

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