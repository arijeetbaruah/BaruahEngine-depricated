#include "../include/Application.h"
#include "../include/Log.h"

#include "../include/Events/ApplicationEvent.h"

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
		WindowResizeEvent e(1280, 720);
		BE_TRACE(e.ToString());

		while (true)
		{

		}
	}
}
