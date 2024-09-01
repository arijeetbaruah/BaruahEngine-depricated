#include "../include/SandboxApp.h"
#include "BaruahEngine.h"

SandboxApp::SandboxApp()
{
	PushOverlay(new Baruah::ImGuiLayer());
}

SandboxApp::~SandboxApp()
{
}
