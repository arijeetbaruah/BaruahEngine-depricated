#pragma once

#include "Rendering/GraphicsContext.h"

struct GLFWwindow;

namespace Baruah {
	class VulkanContext : public GraphicsContext
	{
	public:
		VulkanContext(GLFWwindow* windowHandle);

		void Init() override;
		void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}
