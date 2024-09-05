workspace "BaruahEngine"
	configurations { "Debug", "Release", "Dist" }
	architecture "x64"
    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "BaruahEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "BaruahEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "BaruahEngine/vendor/imgui"
IncludeDir["Vulkan"] = "BaruahEngine/vendor/vulkan/include"
IncludeDir["glm"] = "vendor/glm"

include "BaruahEngine/vendor/GLFW"
include "BaruahEngine/vendor/Glad"
include "BaruahEngine/vendor/imgui"

project "BaruahEngine"
    location "BaruahEngine"
    kind "StaticLib"
	language "C++"
	staticruntime "on"
    cppdialect "c++20"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "bepch.h"
    pchsource "BaruahEngine/src/bepch.cpp"

    files
    {
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/include/**.h",
        "%{prj.name}/include/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/include",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.Vulkan}",
        "%{IncludeDir.glm}"
    }

    defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

    links { "GLFW", "Glad", "ImGui", "opengl32.lib" }

    filter "system:windows"
        systemversion "latest"

        defines { "BE_PLATFORM_WINDOW", "BE_BUILD_DLL", "GLFW_INCLUDE_NONE" }

    filter "configurations:Debug"
        defines "BE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "BE_Release"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "BE_Dist"
        runtime "Release"
        optimize "on"

project "Sandbox"
    location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "on"
    cppdialect "c++20"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/include/**.h"
    }

    includedirs
    {
        "BaruahEngine/vendor/spdlog/include",
        "BaruahEngine/include",
        "BaruahEngine/vendor",
        "%{IncludeDir.glm}",
        "${prj.name}/include"
    }

    links
    {
        "BaruahEngine", "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "BE_PLATFORM_WINDOW"
        }

    filter "configurations:Debug"
        defines "BE_DEBUG"
        defines "HZ_DEBUG"
        symbols "on"

    filter "configurations:Release"
        defines "BE_Release"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "BE_Dist"
        runtime "Release"
        optimize "on"
