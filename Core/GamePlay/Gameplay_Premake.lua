project "Gameplay"
    kind "StaticLib"
    language "C++"

    files {
        "**.h",
        "**.cpp",
        "*.lua"
    }

    --Third party
    importGLFW()
    importGLAD()
    importSTB()

    --Core
    importWindow()
    importGraphics()
    importTimer()
    importInput()