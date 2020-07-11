
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
		SRC_DIR.. "vulkan.c",
		SRC_DIR.. "window.c"
	}

	filter "system:windows"
		   defines{"_GLFW_WIN32"}
		   files{
			   SRC_DIR.. "win32_platform.h",
			   SRC_DIR.. "win32_joystick.h",
			   SRC_DIR.. "wgl_context.h",
			   SRC_DIR.. "egl_context.h",
			   SRC_DIR.. "osmesa_context.h",
			   
			   INCLUDE_DIR.. "*.h",

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

	includedirs{
		"src/",
		"include/glfw",
	}


	-- Imports


	-- Misc
	disablewarnings{
		-- no real way around this at the moment :|
		26812,	-- The enum type 'VkFormat' is unscoped. Prefer 'enum class' over 'enum' (Enum.3)
	}
