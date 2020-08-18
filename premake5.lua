workspace "ToyEngine"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "QAQ/vendor/GLFW/include"
IncludeDir["GLAD"] = "QAQ/vendor/GLAD/include"
IncludeDir["ImGui"] = "QAQ/vendor/imgui"
IncludeDir["glm"] = "QAQ/vendor/glm"

group "Dependencies"
	include "QAQ/vendor/GLFW"
	include "QAQ/vendor/Glad"
	include "QAQ/vendor/imgui"
group ""


project "QAQ"
	location "QAQ"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "qaqpch.h"
	pchsource "QAQ/src/qaqpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links 
	{ 
		"GLFW",
		"opengl32.lib",
		"GLAD",
		"ImGui"
	}


	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"QAQ_PLATFORM_WINDOWS",
			"QAQ_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "QAQ_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "QAQ_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "QAQ_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"QAQ/vendor/spdlog/include",
		"QAQ/src",
		"%{IncludeDir.glm}",
		"QAQ/vendor",
	}

	links
	{
		"QAQ"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"QAQ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "QAQ_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "QAQ_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "QAQ_DIST"
		runtime "Release"
		optimize "On"