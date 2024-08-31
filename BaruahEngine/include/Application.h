#pragma once

#include "Core.h"
#include "./Platform/WindowsWindow.h"
#include "./Events/ApplicationEvent.h"

namespace Baruah {
	class BARUAH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);
		void Run();

	public:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be defined in client
	Application* CreateApplication();
}

