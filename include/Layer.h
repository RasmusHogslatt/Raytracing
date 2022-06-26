#pragma once

#include <imgui.h>

class Layer
{
public:
	virtual ~Layer() = default;

	virtual void onAttach() {}
	virtual void onDetach() {}

	virtual void onRender() {}
};

class ExampleLayer : public Layer
{
	virtual void onRender() override
	{

		//ImGui::ShowDemoWindow();
	}
};