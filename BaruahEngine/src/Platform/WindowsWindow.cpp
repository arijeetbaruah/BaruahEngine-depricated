#include "bepch.h"

#include "Platform/WindowsWindow.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

#include "glad/glad.h"
#include <GLFW/glfw3.h>

namespace Baruah {
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int errorCode, const char* message)
	{
		BE_CORE_ERROR("GFLW Error({0}): {1}", errorCode, message);
	}

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
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)datum.Width, (int)datum.Height, datum.Title.c_str(), nullptr, nullptr);
		m_Context = new OpenGLContext(m_Window);
		m_Context->Init();

		glfwMakeContextCurrent(m_Window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BE_CORE_ASSERT(status, "Failed to Initialize Glad");
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		SetWindowSizeCallback();
		SetWindowCloseCallback();
		SetWindowFocusCallback();
		SetKeyCallback();
		SetMouseCallback();
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::SetWindowSizeCallback()
	{
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});
	}

	void WindowsWindow::SetWindowCloseCallback()
	{
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowCloseEvent event;
			data.EventCallback(event);
		});
	}

	void WindowsWindow::SetWindowFocusCallback()
	{
		glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			if (focused == GL_TRUE)
			{
				WindowFocusEvent focusEvent;
				data.EventCallback(focusEvent);
			}
			else
			{
				WindowUnFocusEvent unfocusEvent;
				data.EventCallback(unfocusEvent);
			}

		});
	}

	void WindowsWindow::SetKeyCallback()
	{
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			if (action == GLFW_PRESS)
			{
				KeyPressedEvent event(key, 0);
				data.EventCallback(event);
			}
			else if (action == GLFW_RELEASE)
			{
				KeyReleasedEvent event(key);
				data.EventCallback(event);
			}
			else if (action == GLFW_REPEAT)
			{
				KeyPressedEvent event(key, 1);
				data.EventCallback(event);
			}
		});
	}

	void WindowsWindow::SetMouseCallback()
	{
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			Event* event = nullptr;

			if (action == GLFW_PRESS)
			{
				MouseButtonPressedEvent event(button);
				data.EventCallback(event);
			}
			else if (action == GLFW_RELEASE)
			{
				MouseButtonReleasedEvent event(button);
				data.EventCallback(event);
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event(xoffset, yoffset);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xpos, (float)ypos);
			data.EventCallback(event);
		});
	}

	void* WindowsWindow::GetNativeWindow()
	{
		return m_Window;
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
