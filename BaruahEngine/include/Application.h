#pragma once

#include "Core.h"
#include "Platform/WindowsWindow.h"
#include "Events/ApplicationEvent.h"
#include "Layer.h"
#include "LayerStack.h"

#include "ImGui/ImGuiLayer.h"

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

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	public:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;

		static Application* s_Instance;
	};

	//To be defined in client
	Application* CreateApplication();
}

