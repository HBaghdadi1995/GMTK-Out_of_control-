project "Application"
    kind "ConsoleApp"
    language "C++"

    files {
        "**.h",
        "**.cpp",
        "*.lua"
    }

    --Third party
    importGLFW()
    importGLAD()

    --Core
    importWindow()

    --includedirs {"../Window/src"}
    --links{"Window"}
    