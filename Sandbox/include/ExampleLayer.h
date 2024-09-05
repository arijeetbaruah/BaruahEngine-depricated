#pragma once

#include <BaruahEngine.h>

#include "imgui/imgui.h"

class ExampleLayer : public Baruah::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}
};
