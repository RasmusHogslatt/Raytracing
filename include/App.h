#pragma once

#include <Texture.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <cstdlib>
#include <memory>
#include <Layer.h>
#include <vector>
#include <functional>
#include <iostream>

static void glfw_error_callback(int error, const char* description);

class App
{
public:
	App(int width = 1900, int height = 900);

	~App();

	void updateWindowSizeAndPosition();

	/// <summary>
	/// Runs application loop
	/// </summary>
	void run();

	/// <summary>
	/// Intializations before loop starts
	/// </summary>
	void startUp();


	/// <summary>
	/// Do things in application loop using layers
	/// </summary>
	void update();

	void render();
	void renderUI();

	/// <summary>
	/// After application loop ends
	/// </summary>
	void close();

	static App* instance_;
private:
	void GUI();

private:
	GLFWwindow* window_ = nullptr;
	int width_, height_;
	ImVec4 clearColor_ = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	Texture viewportTexture_;
	Texture renderTexture_;
	int x = 0;
	ImVec2 pos = ImVec2(0,0);
	std::vector<ImVec2> positions; // Construct objects from positions
};

/*
* void Render()
{
    your raytracing parts here
}

void RenderUi()
{
    your imgui calls here
}

while (!glfwDindowShouldClose(window))
{
    Update();
    Render();
    RenderUi();
}
*/