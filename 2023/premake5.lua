project "2023"
    configurations { "Debug", "Release" }
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    architecture "x64"
    targetdir "bin/%{cfg.buildcfg}"

    files { "**.cpp", "**.h" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
