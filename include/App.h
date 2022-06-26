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

	/// <summary>
	/// After application loop ends
	/// </summary>
	void close();



	template<typename T>
	void pushLayer()
	{
		static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not subclass of Layer!");
		layerStack_.emplace_back(std::make_shared<T>())->onAttach();
	}

	static App* instance_;
	void pushLayer(const std::shared_ptr<Layer>& layer) { layerStack_.emplace_back(layer); layer->onAttach(); }
private:
	void GUI();

private:
	GLFWwindow* window_ = nullptr;
	int width_, height_;
	ImVec4 clearColor_ = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	std::vector<std::shared_ptr<Layer>> layerStack_;
	bool closeApplication_ = false;
	Texture viewportTexture_;
	Texture renderTexture_;
};