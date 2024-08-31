#pragma once

#include "Event.h"

namespace Baruah {
	class BARUAH_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode) : m_KeyCode(keycode) {}
		int m_KeyCode;
	};

	class BARUAH_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount);
	
		inline int GetRepeatCount() const { return m_RepeatCount; }
		
		std::string ToString() const override;

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class BARUAH_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode);

		std::string ToString() const override;

		EVENT_CLASS_TYPE(KeyReleased)
	};
}
