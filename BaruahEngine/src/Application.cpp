#include "bepch.h"

#include "../include/Application.h"
#include <glad/glad.h>

#include "../include/Events/ApplicationEvent.h"

namespace Baruah {
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		BE_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

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

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
			{
				break;
			}
		}
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		BE_TRACE(e.ToString());

		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack) {
				layer->OnUpdate();
			}

			m_Window->OnUpdate();
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}
