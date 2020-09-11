project "QAQnut"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/QAQ/vendor/spdlog/include",
		"%{wks.location}/QAQ/src",
		"%{wks.location}/QAQ/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.lua}"
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