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
    importGameplay()

    filter "configurations:Dist"
        defines { "NDEBUG"}
        optimize "On"

        targetdir ("../../Dist")

        prebuildcommands
        {
            ("{COPY} %{wks.location}/Src/ %{wks.location}/Dist/Src/")
            ("{COPY} %{wks.location}/Docs/ %{wks.location}/Dist/Docs/")
        }

    filter {}

    --includedirs {"../Window/src"}
    --links{"Window"}
    