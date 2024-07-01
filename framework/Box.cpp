#include "Box.hpp"
#include <numbers>
#include <cmath>


Box::Box(glm::vec3 const& m, glm::vec3 const& r, std::string const& na, Color const& fa) : Shape{ na,fa }, min_(m), max_(r) {

}
float Box::area() const {
	
	float länge = std::abs(max_.x - min_.x);
	float breite = std::abs(max_.y - min_.y);
	float höhe = std::abs(max_.z - min_.z);

	
	float oberfläche = 2.0f * (länge * breite + länge * höhe + breite * höhe);

	return oberfläche;
}
	

float Box::volume() const {

	// Länge, Breite und Höhe berechnen
	float länge = std::abs(max_.x - min_.x);
	float breite = std::abs(max_.y - min_.y);
	float höhe = std::abs(max_.z - min_.z);
	

	// Volumen berechnen: L * B * H
	float volume = länge * breite * höhe;
	return volume;
}
std::ostream& Box::print(std::ostream& os) const {
	// Aufruf der Basisklassen-Print-Methode
	Shape::print(os);
	os << ", Min: (" << min_.x << ", " << min_.y << ", " << min_.z << "), Max: (" << max_.x << ", " << max_.y << ", " << max_.z << ")";
	return os;
}