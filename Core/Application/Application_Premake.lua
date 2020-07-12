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
    importSTB()

    --Core
    importWindow()
    importGraphics()
    importTimer()
    importInput()

    filter "configurations:Dist"
        defines { "NDEBUG"}
        optimize "On"

        targetdir ("../../Dist")

        prebuildcommands
        {
            ("{COPY} %{wks.location}/Src/ %{wks.location}/Dist/Src/")
        }

    filter {}

    --includedirs {"../Window/src"}
    --links{"Window"}
    