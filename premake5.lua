include "./vendor/premake/premake_customization/solution_items.lua"

workspace "ToyEngine"
	architecture "x86_64"
	startproject "QAQnut"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/QAQ/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/QAQ/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/QAQ/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/QAQ/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/QAQ/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/QAQ/vendor/entt/include"
IncludeDir["lua"] = "%{wks.location}/QAQ/vendor/lua535/include"

group "Dependencies"
	include "vendor/premake"
	include "QAQ/vendor/GLFW"
	include "QAQ/vendor/Glad"
	include "QAQ/vendor/imgui"
group ""

include "QAQ"
include "Sandbox"
include "QAQnut"
