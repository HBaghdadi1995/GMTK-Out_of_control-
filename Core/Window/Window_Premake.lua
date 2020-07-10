project "Window"
    kind "StaticLib"
    language "C++"

    files {
        "**.h",
        "**.cpp",
        "*.lua"
    }
    
    --Third party
    importGLFW()