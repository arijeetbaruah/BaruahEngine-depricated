#include "../include/Application.h"
#include "../include/Log.h"

namespace Baruah {
	Application::Application()
	{
		Baruah::Log::Initialize();
		BE_CORE_INFO("Welcome to Baruah Engine");
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (true)
		{

		}
	}
}
