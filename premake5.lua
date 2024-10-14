workspace "Gratify"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Gratify"
    location "Gratify"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "PLATFORM_WINDOWS",
            "BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "GF_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "GF_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "GF_DIST"
        symbols "On"



project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"
    
        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
        files 
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }
    
        includedirs
        {
            "Gratify/vendor/spdlog/include",
            "Gratify/src"
        }

        links
        {
            "Gratify"
        }
    
        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"
    
            defines
            {
                "PLATFORM_WINDOWS"
            }
    
        filter "configurations:Debug"
            defines "GF_DEBUG"
            symbols "On"
        
        filter "configurations:Release"
            defines "GF_RELEASE"
            symbols "On"
    
        filter "configurations:Dist"
            defines "GF_DIST"
            symbols "On"
    