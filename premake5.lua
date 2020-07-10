
workspace "OutOfControl"
    cppdialect "C++17"
    
    configurations { "Debug", "Release"}
    platforms {"x64"}

    filter "configurations:Debug"
        defines { "Debug"}
        optimize "Off"
    
    filter "configurations:Release"
        defines { "NDEBUG"}
        optimize "On"
    filter {}

    filter "system:windows"
		defines{"WINDOWS"}
    filter{}
    
    group"External"

    group"Core"
        dofile "Core/Application/Application_Premake.lua"
        