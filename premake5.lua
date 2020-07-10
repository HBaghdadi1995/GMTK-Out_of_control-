
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

    dofile "External_Dependencies.lua"
    dofile "Core_Dependencies.lua"
    
    group"External"
        dofile "External/glfw/glfw_Premake.lua"

    group"Core"
        dofile "Core/Window/Window_Premake.lua"
        dofile "Core/Application/Application_Premake.lua"
        