-- QAQ Dependencies

VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["stb_image"] = "%{wks.location}/QAQ/vendor/stb_image"
IncludeDir["yaml_cpp"] = "%{wks.location}/QAQ/vendor/yaml-cpp/include"
IncludeDir["GLFW"] = "%{wks.location}/QAQ/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/QAQ/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/QAQ/vendor/ImGui"
IncludeDir["ImGuizmo"] = "%{wks.location}/QAQ/vendor/ImGuizmo"
IncludeDir["glm"] = "%{wks.location}/QAQ/vendor/glm"
IncludeDir["entt"] = "%{wks.location}/QAQ/vendor/entt/include"
IncludeDir["shaderc"] = "%{wks.location}/QAQ/vendor/shaderc/include"
IncludeDir["SPIRV_Cross"] = "%{wks.location}/QAQ/vendor/SPIRV-Cross"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"
IncludeDir["Box2D"] = "%{wks.location}/QAQ/vendor/Box2D/include"
IncludeDir["mono"] = "%{wks.location}/QAQ/vendor/mono/include"
IncludeDir["filewatch"] = "%{wks.location}/QAQ/vendor/filewatch"

LibraryDir = {}

LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"
LibraryDir["VulkanSDK_Debug"] = "%{VULKAN_SDK}/Lib"
LibraryDir["VulkanSDK_DebugDLL"] = "%{VULKAN_SDK}/Bin"
LibraryDir["mono"] = "%{wks.location}/QAQ/vendor/mono/lib/%{cfg.buildcfg}"

Library = {}
Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
Library["VulkanUtils"] = "%{LibraryDir.VulkanSDK}/VkLayer_utils.lib"
Library["mono"] = "%{LibraryDir.mono}/libmono-static-sgen.lib"

Library["ShaderC_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/shaderc_sharedd.lib"
Library["SPIRV_Cross_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/spirv-cross-cored.lib"
Library["SPIRV_Cross_GLSL_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/spirv-cross-glsld.lib"
Library["SPIRV_Tools_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/SPIRV-Toolsd.lib"

Library["ShaderC_Release"] = "%{LibraryDir.VulkanSDK}/shaderc_shared.lib"
Library["SPIRV_Cross_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-core.lib"
Library["SPIRV_Cross_GLSL_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsl.lib"

-- Windows
Library["WinSock"] = "Ws2_32.lib"
Library["WinMM"] = "Winmm.lib"
Library["WinVersion"] = "Version.lib"
Library["BCrypt"] = "Bcrypt.lib"