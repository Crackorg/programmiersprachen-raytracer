#ifndef sphere
#define sphere

#include "shape.hpp"
#include <glm/vec3.hpp>






class Sphere : public Shape {
public :
	Sphere(glm::vec3 const& mitte , float radius, std::string const& name , Color const& farbe);
    ~Sphere();
	float area() const override;
	float volume() const override;

	std::ostream& print(std::ostream& os) const override;

	 HitPoint intersect(Ray const& ray) const; //methode für schnitt strahl/kugel

private : 
	glm::vec3 mitte_;
	float radius_; 
		
};

#endif sphere 