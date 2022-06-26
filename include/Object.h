#pragma once
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

class Object
{
public:
	Object(const glm::vec3& position = glm::vec3(0), const glm::vec3& normal = glm::vec3(0));
protected:
	glm::vec3 position_;
	glm::vec3 normal_;
};

class Sphere : public Object
{
public:
	Sphere(const glm::vec3& position = glm::vec3(0), const glm::vec3& normal = glm::vec3(0), float radius = 1.0f);

private:
	float radius_;
};