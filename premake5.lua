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

    files {"AoCUtilities.h", "DayBase.h", "Common.h", "Timer.h"}

include "2015/premake5.lua"
include "2016/premake5.lua"
include "2017/premake5.lua"
include "2018/premake5.lua"
include "2019/premake5.lua"