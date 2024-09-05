#include "Window.h"
#include "Rendering/GraphicsContext.h"

struct GLFWwindow;

namespace Baruah {
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowDatum& datum);
		virtual ~WindowsWindow();

		void OnUpdate() override;
		
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }
		
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync(bool enabled) const override;

	private:
		virtual void Initialize(const WindowDatum& datum);
		virtual void Shutdown();

		void SetWindowSizeCallback();
		void SetWindowCloseCallback();
		void SetWindowFocusCallback();
		void SetKeyCallback();
		void SetMouseCallback();
	private:
		GLFWwindow* m_Window;
		GraphicsContext* m_Context;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;

		// Inherited via Window
		void* GetNativeWindow() override;
	};
}
