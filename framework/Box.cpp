#include "Box.hpp"
#include <numbers>
#include <cmath>


Box::Box(glm::vec3 const& m, glm::vec3 const& r, std::string const& na, Color const& fa) : Shape{ na,fa }, min_(m), max_(r) {

}
float Box::area() const {
	
	float l�nge = std::abs(max_.x - min_.x);
	float breite = std::abs(max_.y - min_.y);
	float h�he = std::abs(max_.z - min_.z);

	
	float oberfl�che = 2.0f * (l�nge * breite + l�nge * h�he + breite * h�he);

	return oberfl�che;
}
	

float Box::volume() const {

	// L�nge, Breite und H�he berechnen
	float l�nge = std::abs(max_.x - min_.x);
	float breite = std::abs(max_.y - min_.y);
	float h�he = std::abs(max_.z - min_.z);
	

	// Volumen berechnen: L * B * H
	float volume = l�nge * breite * h�he;
	return volume;
}
std::ostream& Box::print(std::ostream& os) const {
	// Aufruf der Basisklassen-Print-Methode
	Shape::print(os);
	os << ", Min: (" << min_.x << ", " << min_.y << ", " << min_.z << "), Max: (" << max_.x << ", " << max_.y << ", " << max_.z << ")";
	return os;
}