#pragma once

#include "Core.h"
#include "Platform/WindowsWindow.h"
#include "Events/ApplicationEvent.h"
#include "Layer.h"
#include "LayerStack.h"

namespace Baruah {
	class BARUAH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);
		void Run();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	public:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be defined in client
	Application* CreateApplication();
}

