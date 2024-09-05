#include "../include/SandboxApp.h"
#include "BaruahEngine.h"
#include "../include/ExampleLayer.h"

SandboxApp::SandboxApp()
{
	PushLayer(new ExampleLayer());
}

SandboxApp::~SandboxApp()
{
}
