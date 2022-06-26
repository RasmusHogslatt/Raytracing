#include "Object.h"

Object::Object(const glm::vec3& position, const glm::vec3& normal) : position_{ position }, normal_{ normal } {}

Sphere::Sphere(const glm::vec3& position, const glm::vec3& normal, float radius) : Object(position, normal), radius_{radius} {}
