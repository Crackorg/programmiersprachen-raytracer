#ifndef sphere
#define sphere

#include "shape.hpp"
#include <glm/vec3.hpp >




class Sphere : public Shape {
public :
	Sphere(glm::vec3 const& mitte , float radius);
	float area() const override;
	float volume() const override;

private : 
	glm::vec3 mitte_;
	float radius_; 
		
};

#endif sphere 