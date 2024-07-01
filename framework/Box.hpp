#include <glm/vec3.hpp >
#include <shape.hpp>

#ifndef boxe
#define boxe


class Box : public Shape {
public:
	Box(glm::vec3 const& min, glm::vec3 const& max, std::string const& na , Color const& fa);
	float area() const override;
	float volume() const override;
	std::ostream& print(std::ostream& os) const override;
private:
	glm::vec3 min_;
	glm::vec3 max_;

};

#endif boxe