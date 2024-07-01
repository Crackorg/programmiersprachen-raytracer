#include <iostream>
#include "Box.hpp"  
#include "color.hpp"
#include "Shape.hpp"
#include "Sphere.hpp"

int main() {
   
    Color günther;  

    
    glm::vec3 minPoint(-1.0f, -1.0f, -1.0f);
    glm::vec3 maxPoint(1.0f, 1.0f, 1.0f);
    Box myBox(minPoint, maxPoint, "MyBox", günther);

    
    myBox.print(std::cout) << std::endl;

    Color red = { 1.0f, 0.0f, 0.0f }; 
    glm::vec3 center(0.0f, 0.0f, 0.0f); 
    Sphere sphe(center, 5.0f, "Kugel", red);

    sphe.print(std::cout) << std::endl;

    //aufgabe 5.8
    Color redi{255, 0, 0};
    glm::vec3 position{0.0f, 0.0f, 0.0f };
    
    Sphere* s1 = new Sphere{position, 1.2f, "sphere0", redi };
    Shape* s2 = new Sphere{position, 1.2f, "sphere1", redi};
    
    s1 -> print(std::cout);
    s2 -> print(std::cout);
    
    delete s1;
    delete s2; // ohne virtual wird sphere 1 nicht richtig destroyed ?? ohne virtual speicherlack ? 


    return 0;
}