#pragma once

#include <Renderer.h>
#include <glm/vec2.hpp>
#include <glm/common.hpp>
#include <glm/glm.hpp>

Renderer::Renderer(Texture& texture) : image_{ texture }, width_{ texture.getWidth() }, height_{ texture.getHeight() }
{
	scene_.push_back(Sphere());
}

glm::vec4 Renderer::trace(glm::vec3& rayOrigo, glm::vec3& rayDirection, const int& depth)
{
	return glm::vec4();
}

void Renderer::Render()
{
	float aspectRatio = (float)width_ / (float)height_;
	for (uint32_t y = 0; y < height_; ++y)
	{
		for (uint32_t x = 0; x < width_; ++x)
		{
			glm::vec2 coord = { (2.0f * ((float)x + 0.5) * (1.0 / (float)width_) - 1.0f) * aspectRatio, (1.0f - 2.0f * (((float)y + 0.5f) * (1.0f / (float)height_))) };
			glm::vec3 rayDirection = glm::vec3(coord, -1.0f);
			rayDirection = normalize(rayDirection);
			glm::vec4 result = trace(cameraPosition_, rayDirection, 0);

			image_.setPixelColor(x, y, ImVec4(x, y, x, 1));
			//image_.data_[x + y * width_] = 0.5;
		}
	}
}

glm::vec3 Renderer::getInitialRay()
{
	return glm::vec3(0);
}



unsigned char* Renderer::getImageTextureData() const
{
	return image_.data_;
}