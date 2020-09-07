workspace "ToyEngine"
	architecture "x86_64"
	startproject "QAQNut"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "QAQ/vendor/GLFW/include"
IncludeDir["GLAD"] = "QAQ/vendor/GLAD/include"
IncludeDir["ImGui"] = "QAQ/vendor/imgui"
IncludeDir["glm"] = "QAQ/vendor/glm"
IncludeDir["stb_image"] = "QAQ/vendor/stb_image"
IncludeDir["entt"] = "QAQ/vendor/entt/include"

group "Dependencies"
	include "QAQ/vendor/GLFW"
	include "QAQ/vendor/Glad"
	include "QAQ/vendor/imgui"
group ""


project "QAQ"
	location "QAQ"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"


	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "qaqpch.h"
	pchsource "QAQ/src/qaqpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}",
	}

	links 
	{ 
		"GLFW",
		"opengl32.lib",
		"GLAD",
		"ImGui"
	}


	filter "system:windows"
		systemversion "latest"

		defines
		{
			"QAQ_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		
	filter "configurations:Debug"
		defines "QAQ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "QAQ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "QAQ_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "on"
	cppdialect "C++17"


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
		"%{IncludeDir.entt}"
	}

	links
	{
		"QAQ"
	}

	filter "system:windows"
		systemversion "latest"


	filter "configurations:Debug"
		defines "QAQ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "QAQ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "QAQ_DIST"
		runtime "Release"
		optimize "on"

project "QAQNut"
	location "QAQNut"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"QAQ/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"QAQ"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "QAQ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "QAQ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "QAQ_DIST"
		runtime "Release"
		optimize "on"