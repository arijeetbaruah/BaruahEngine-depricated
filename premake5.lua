workspace "BaruahEngine"
	configurations { "Debug", "Release", "Dist" }
	architecture "x64"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "BaruahEngine"
    location "BaruahEngine"
    kind "SharedLib"
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
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "c++20"
        staticruntime "On"
        systemversion "latest"

        defines { "BE_PLATFORM_WINDOW", "BE_BUILD_DLL" }

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
        "BaruahEngine/include"
    }

    links
    {
        "BaruahEngine"
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
