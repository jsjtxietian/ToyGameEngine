include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

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



group "Dependencies"
	include "vendor/premake"
	include "QAQ/vendor/GLFW"
	include "QAQ/vendor/Glad"
	include "QAQ/vendor/imgui"
	include "QAQ/vendor/yaml-cpp"
	include "QAQ/vendor/Box2D"
group ""

include "QAQ"
include "Sandbox"
include "QAQnut"
include "CSharpEngine"