workspace "AdventOfCodeWorkspace"
    configurations { "Debug", "Release" }

project "2015"
    configurations { "Debug", "Release" }
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"

    files { "AdventOfCode/2015/**.cpp", "AdventOfCode/2015/**.h" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
