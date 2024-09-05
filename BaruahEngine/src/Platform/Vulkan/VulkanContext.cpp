#include "bepch.h"

#include "Platform/Vulkan/VulkanContext.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Baruah {
	VulkanContext::VulkanContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		BE_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void VulkanContext::Init()
	{
		if (!glfwVulkanSupported())
		{
			BE_CORE_ERROR("Vulkan is not supported");
			return;
		}

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BE_CORE_ASSERT(status, "Failed to initialize Glad!");
	}

	void VulkanContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}
