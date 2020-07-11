
SRC_DIR      = "./src/"
INCLUDE_DIR      = "./include/"

project "GLAD"
	kind "StaticLib"
	language "C"
	targetdir "bin/%{cfg.buildcfg}"

	files{
		INCLUDE_DIR.. "glad/glad.h",
		SRC_DIR.. "glad.c"
    }
    
	includedirs{
		INCLUDE_DIR
	}