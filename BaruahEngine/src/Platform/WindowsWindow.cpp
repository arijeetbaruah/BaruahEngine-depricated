#include "bepch.h"
#include "../../include/Platform/WindowsWindow.h"
#include "../../include/Log.h"

namespace Baruah {
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowDatum& datum)
	{
		return new WindowsWindow(datum);
	}

	WindowsWindow::WindowsWindow(const WindowDatum& datum)
	{
		Initialize(datum);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Initialize(const WindowDatum& datum)
	{
		m_Data.Title = datum.Title;
		m_Data.Width = datum.Width;
		m_Data.Height = datum.Height;

		BE_CORE_INFO("Creating window {0} ({1}, {2})", datum.Title, datum.Width, datum.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			BE_CORE_ASSERT(success, "Could not initialize GLFW");


			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)datum.Width, (int)datum.Height, datum.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync(bool enabled) const
	{
		return m_Data.VSync;
	}
}
