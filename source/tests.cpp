#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>


#include "Sphere.hpp" // Include der Sphere-Klasse

TEST_CASE("Berechnung der Oberfläche einer Kugel", "[Sphere]") {
    glm::vec3 center(0.0f, 0.0f, 0.0f);
    float radius = 5.0f;
    Sphere sph(center, radius);

    //  fall 1
    REQUIRE(sph.area() == Approx(4.0f * (3.1415f*3.1415f) * radius).epsilon(0.001)); // epsilon() für Toleranz

    // fall 2 
    float radius2 = 3.0f;
    Sphere sphere2(center, radius2);
    REQUIRE(sphere2.area() == Approx(4.0f * (3.1415f * 3.1415f) * radius2).epsilon(0.001));

} 
TEST_CASE("Berechnung des Volumens und der Oberfläche einer Kugel", "[Sphere]") {
    glm::vec3 center(0.0f, 0.0f, 0.0f);
    float radius = 5.0f;
    Sphere sph(center, radius);

    // Testfall 1: Volumen der Kugel überprüfen
    REQUIRE(sph.volume() == Approx(523.6f).epsilon(0.001)); // epsilon() für Toleranz

    // Testfall 2: Oberfläche der Kugel überprüfen
    float radius2 = 3.0f;
    Sphere sphere2(center, radius2);
    REQUIRE(sphere2.volume() == Approx((4.0 / 3.0) * 3.1415f * pow(radius2, 3)).epsilon(0.001));
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
