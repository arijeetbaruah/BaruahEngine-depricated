#include "bepch.h"

#include "../include/Application.h"

#include "../include/Events/ApplicationEvent.h"

namespace Baruah {
	Application::Application()
	{
		Baruah::Log::Initialize();
		BE_CORE_INFO("Welcome to Baruah Engine");

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BE_BIND(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		BE_CORE_INFO("{0}", e.ToString());
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BE_BIND(Application::OnWindowClose));
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		BE_TRACE(e.ToString());

		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}
