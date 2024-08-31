#include "bepch.h"

#include "../include/Application.h"

#include "../include/Events/ApplicationEvent.h"

namespace Baruah {
	Application::Application()
	{
		Baruah::Log::Initialize();
		BE_CORE_INFO("Welcome to Baruah Engine");

		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		BE_TRACE(e.ToString());

		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}
