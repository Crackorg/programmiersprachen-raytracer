#ifndef shapy 
#define shapy
#include <string>
#include "color.hpp"
#include <iostream> 
#include "Hit_Point.hpp"
#include "Ray.hpp"


class Shape {
public:
	Shape(std::string const& name, Color const& farbe);
	virtual ~Shape(); 
	virtual float area() const = 0 ;
	virtual float volume() const = 0; 
	virtual std::ostream& print(std::ostream& os) const;

	// friend -> für zugriff auf private member variablen
    friend std::ostream& operator<<(std::ostream& os, Shape const& s);

public:
	std::string name_;
	Color farbe_;

};

#endif 