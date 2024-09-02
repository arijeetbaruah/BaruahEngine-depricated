#pragma once

#include "bepch.h"
#include "Core.h"
#include "Events/Event.h"

namespace Baruah {
	struct WindowDatum
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowDatum(const std::string& title = "Baruah Engine", unsigned int width = 1280, unsigned int height = 720) : Title(title), Width(width), Height(height) {}
	};

	class BARUAH_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Baruah::Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync(bool enabled) const = 0;

		virtual void* GetNativeWindow() = 0;

		static Window* Create(const WindowDatum& datum = WindowDatum());
	};
}
