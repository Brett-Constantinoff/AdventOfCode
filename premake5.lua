workspace "AdventOfCode"
    configurations { "Debug", "Release" }
    startproject "2016"
    flags { "MultiProcessorCompile" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        optimize "Speed"
        flags { "LinkTimeOptimization" }

include "2015/premake5.lua"
include "2016/premake5.lua"
include "2017/premake5.lua"