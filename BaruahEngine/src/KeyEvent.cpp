#include "../include/Events/KeyEvent.h"
#include <sstream>

namespace Baruah {
	KeyPressedEvent::KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_RepeatCount(repeatCount)
	{
	}

	std::string KeyPressedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
		return ss.str();
	}

	KeyReleasedEvent::KeyReleasedEvent(int keycode) : KeyEvent(keycode)
	{
	}

	std::string KeyReleasedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << m_KeyCode;
		return ss.str();
	}
}
