project "Graphics"
    kind "StaticLib"
    language "C++"

    files {
        "**.h",
        "**.cpp",
        "*.lua"
    }
    
    --Third party
    importGLAD()
    importSTB()
