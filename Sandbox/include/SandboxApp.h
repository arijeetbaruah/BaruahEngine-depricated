#pragma once

#include <BaruahEngine.h>

class SandboxApp : public Baruah::Application
{
public:
	SandboxApp();
	~SandboxApp();
};

Baruah::Application* Baruah::CreateApplication()
{
	return new SandboxApp();
}
