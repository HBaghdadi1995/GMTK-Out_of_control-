
workspace "OutOfControl"
    cppdialect "C++17"
    
    configurations { "Debug", "Release"}
    Platforms {"x64"}

    filter "configurations:Debug"
        defines { "Debug"}
        optimize "Off"
    
    filter "configurations:Release"
        defines { "NDEBUG"}
        optimize "On"
    filters {}

    filter "system:windows"
		defines{"WINDOWS"}
    filter{}
    
    group"External"

    group"Core"
        