#include "bepch.h"
#include "Platform/WindowsInput.h"

#include "GLFW/glfw3.h"
#include <Application.h>
#include <Window.h>

namespace Baruah {
    Input* Input::s_Instance = new WindowsInput();

    bool WindowsInput::IsKeyPressedImpl(int keycode)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

        auto state = glfwGetKey(window, keycode);

        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInput::IsMouseButtonPressedImpl(int button)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

        auto state = glfwGetMouseButton(window, button);

        return state == GLFW_PRESS;
    }

    float WindowsInput::GetMouseXImpl()
    {
        return GetMousePositionImpl().first;
    }

    float WindowsInput::GetMouseYImpl()
    {
        return GetMousePositionImpl().second;
    }

    std::pair<float, float> WindowsInput::GetMousePositionImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;

        glfwGetCursorPos(window, &xpos, &ypos);
        return std::pair<float, float>(xpos, ypos);
    }
}

