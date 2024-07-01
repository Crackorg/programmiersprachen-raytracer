#include "shape.hpp"

Shape::Shape(std::string const& nam, Color const& farb) :  name_(nam), farbe_(farb) {

}
std::ostream& Shape::print(std::ostream& os) const {
    os << "Shape: " << name_ << ", Color: (" << farbe_.r << ", " << farbe_.g << ", " << farbe_.b << ")";
    return os;
}

// Überladung des Stream-Operators <<, der die print-Methode aufruft
std::ostream& operator<<(std::ostream& os, Shape const& s) {
    return s.print(os);
}
Shape::~Shape() {
    std::cout << name_ << " destroyed" << std::endl;
}