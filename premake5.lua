workspace "BaruahEngine"
	configurations { "Debug", "Release", "Dist" }
	architecture "x64"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "BaruahEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "BaruahEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "BaruahEngine/vendor/imgui"

include "BaruahEngine/vendor/GLFW"
include "BaruahEngine/vendor/Glad"
include "BaruahEngine/vendor/imgui"

project "BaruahEngine"
    location "BaruahEngine"
    kind "SharedLib"
    language "C++"

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
        "%{IncludeDir.ImGui}"
    }

    links { "GLFW", "Glad", "ImGui", "opengl32.lib" }

    filter "system:windows"
        cppdialect "c++20"
        staticruntime "off"
        systemversion "latest"

        defines { "BE_PLATFORM_WINDOW", "BE_BUILD_DLL", "GLFW_INCLUDE_NONE" }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "BE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "BE_Release"
        optimize "On"

    filter "configurations:Dist"
        defines "BE_Dist"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

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
        "%{IncludeDir.GLFW}",
    }

    links
    {
        "BaruahEngine","GLFW", "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "c++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "BE_PLATFORM_WINDOW"
        }

    filter "configurations:Debug"
        defines "BE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "BE_Release"
        optimize "On"

    filter "configurations:Dist"
        defines "BE_Dist"
        optimize "On"
