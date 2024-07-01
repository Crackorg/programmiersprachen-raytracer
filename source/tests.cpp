#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <Box.hpp>
# include <glm/gtx/intersect.hpp>


#include "Sphere.hpp" // Include der Sphere-Klasse

TEST_CASE("Berechnung der Oberfläche einer Kugel", "[Sphere]") {
    glm::vec3 center(0.0f, 0.0f, 0.0f);
    float radius = 5.0f;
    std::string dummy;
    Color dummy2;
    Sphere sph(center, radius,dummy,dummy2 );

    //  fall 1
    REQUIRE(sph.area() == Approx(4.0f * (3.1415f*3.1415f) * radius).epsilon(0.001)); // epsilon() für Toleranz

    // fall 2 
    float radius2 = 3.0f;
    Sphere sphere2(center, radius2,dummy,dummy2);
    REQUIRE(sphere2.area() == Approx(4.0f * (3.1415f * 3.1415f) * radius2).epsilon(0.001));

} 
TEST_CASE("Berechnung des Volumens und der Oberfläche einer Kugel", "[Sphere]") {
    glm::vec3 center(0.0f, 0.0f, 0.0f);
    float radius = 5.0f;
    std::string dummy;
    Color dummy2;
    Sphere sph(center, radius,dummy,dummy2);

    // Testfall 1: Volumen der Kugel überprüfen
    REQUIRE(sph.volume() == Approx(523.6f).epsilon(0.001)); // epsilon() für Toleranz

    // Testfall 2: Oberfläche der Kugel überprüfen
    float radius2 = 3.0f;
    Sphere sphere2(center, radius2,dummy,dummy2);
    REQUIRE(sphere2.volume() == Approx((4.0 / 3.0) * 3.1415f * pow(radius2, 3)).epsilon(0.001));
}
TEST_CASE("Box volume calculation", "[volume]") {
    // Testfall 1: Box mit positiven Dimensionen
    std::string dummy;
    Color dummy2;
    glm::vec3 min1(0.0f, 0.0f, 0.0f);
    glm::vec3 max1(2.0f, 3.0f, 4.0f);
    Box box1(min1, max1,dummy,dummy2);
    REQUIRE(box1.volume() == Approx(24.0f)); // Volumen = 2 * 3 * 4

    // Testfall 2: Box mit negativen Koordinaten
    glm::vec3 min2(-1.0f, -1.0f, -1.0f);
    glm::vec3 max2(1.0f, 1.0f, 1.0f);
    Box box2(min2, max2,dummy,dummy2);
    REQUIRE(box2.volume() == Approx(8.0f)); // Volumen = 2 * 2 * 2

    // Testfall 3: Box mit gemischten Koordinaten
    glm::vec3 min3(1.0f, 2.0f, 3.0f);
    glm::vec3 max3(4.0f, 6.0f, 8.0f);
    Box box3(min3, max3,dummy,dummy2);
    REQUIRE(box3.volume() == Approx(60.0f)); // Volumen = (4-1) * (6-2) * (8-3)
}

TEST_CASE("Box surface area calculation", "[area]") {
    // Testfall 1: Box mit positiven Dimensionen
    std::string dummy;
    Color dummy2;
    glm::vec3 min1(0.0f, 0.0f, 0.0f);
    glm::vec3 max1(2.0f, 3.0f, 4.0f);
    Box box1(min1, max1,dummy,dummy2);
    REQUIRE(box1.area() == Approx(52.0f)); // Fläche = 2 * (2*3 + 2*4 + 3*4)

    // Testfall 2: Box mit negativen Koordinaten
    glm::vec3 min2(-1.0f, -1.0f, -1.0f);
    glm::vec3 max2(1.0f, 1.0f, 1.0f);
    Box box2(min2, max2,dummy,dummy2);
    REQUIRE(box2.area() == Approx(24.0f)); // Fläche = 2 * (2*2 + 2*2 + 2*2)

    // Testfall 3: Box mit gemischten Koordinaten
    glm::vec3 min3(1.0f, 2.0f, 3.0f);
    glm::vec3 max3(4.0f, 6.0f, 8.0f);
    Box box3(min3, max3,dummy,dummy2);
    REQUIRE(box3.area() == Approx(94.0f)); // Fläche = 2 * (3*4 + 3*5 + 4*5)
}
TEST_CASE(" intersect_ray_sphere ", "[intersechht]")
{
    
    glm::vec3 ray_origin{ 0.0f, 0.0f, 0.0f };
    
   
    glm::vec3 ray_direction{ 0.0f, 0.0f, 1.0f };
    
    glm::vec3 sphere_center{ 0.0f ,0.0f, 5.0f };
    float sphere_radius{ 1.0f };
    float distance = 0.0f;
    auto result = glm::intersectRaySphere(
        ray_origin, ray_direction,
        sphere_center,
        sphere_radius * sphere_radius, 
        distance);

    REQUIRE(distance == Approx(4.0f));
}
TEST_CASE("Test der intersect-Methode der Klasse Sphere", "[intersect]") {
    
    Color red = { 1.0f, 0.0f, 0.0f }; // kugel
    glm::vec3 sphere_center{ 0.0f, 0.0f, 5.0f };
    Sphere sph(sphere_center, 1.0f, "TestSphere", red);

    
    glm::vec3 ray_origin{ 0.0f, 0.0f, 0.0f }; //strahl
    glm::vec3 ray_direction{ 0.0f, 0.0f, 1.0f };
    Ray ray{ ray_origin, ray_direction };

    
    HitPoint hit_point = sph.intersect(ray); // methode

    
    REQUIRE(hit_point.intersected == true); //test der member von hitpoint
    REQUIRE(hit_point.distance == Approx(4.0f));
    REQUIRE(hit_point.object_name == "TestSphere");
    REQUIRE(hit_point.object_color.r == Approx(1.0f));
    REQUIRE(hit_point.object_color.g == Approx(0.0f));
    REQUIRE(hit_point.object_color.b == Approx(0.0f));
    REQUIRE(hit_point.intersection_point == glm::vec3(0.0f, 0.0f, 4.0f));
    REQUIRE(hit_point.intersection_direction == glm::normalize(ray_direction));
}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
