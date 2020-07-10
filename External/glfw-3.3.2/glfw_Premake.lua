
SRC_DIR      = "./src/"
INCLUDE_DIR      = "./include/"

project "GLFW"
	kind "StaticLib"
	language "C"
	targetdir "bin/%{cfg.buildcfg}"

	files{
		SRC_DIR.. "internal.h",
		SRC_DIR.. "mappings.h",

		SRC_DIR.. "context.c",
		SRC_DIR.. "init.c",
		SRC_DIR.. "input.c",
		SRC_DIR.. "monitor.c",
		SRC_DIR.. "window.c",

		INCLUDE_DIR.. "*.h"	,
		"*_premake.lua",
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS"
	}

	--system dependent stuff, look at
	--https://github.com/glfw/glfw/blob/master/src/CMakeLists.txt and
	--https://github.com/glfw/glfw/blob/master/CMakeLists.txt to know what to include
	
	filter "system:windows"
		   defines{"_GLFW_WIN32"}
		   files{
				SRC_DIR.. "win32_platform.h",
				SRC_DIR.. "win32_joystick.h",
				SRC_DIR.. "wgl_context.h",
				SRC_DIR.. "egl_context.h",
				SRC_DIR.. "osmesa_context.h",
				
				SRC_DIR.. "win32_init.c",
				SRC_DIR.. "win32_joystick.c",
				SRC_DIR.. "win32_monitor.c",
				SRC_DIR.. "win32_time.c",
				SRC_DIR.. "win32_thread.c",
				SRC_DIR.. "win32_window.c",
				SRC_DIR.. "wgl_context.c",
				SRC_DIR.. "egl_context.c",
				SRC_DIR.. "osmesa_context.c"

			}

	filter{}

	includedirs{
		"src/",
		"include/glfw",
	}
