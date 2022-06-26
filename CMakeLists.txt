cmake_minimum_required(VERSION 2.8.12...3.22)
project(Gamma VERSION 1.0.0 DESCRIPTION "Gamma" LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

function(enable_warnings target)
target_compile_options(${target} PUBLIC 
$<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
$<$<CXX_COMPILER_ID:AppleClang>:-Wall -Wextra -Wconversion>
$<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -Wconversion>
$<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wconversion>
)
endfunction()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH})

find_package(OpenGL REQUIRED)
add_subdirectory(external)

set(HEADER_FILES
	include/App.h
    include/Layer.h
    include/Texture.h
    include/Renderer.h
    include/Object.h
    include/Material.h
)

set(SOURCE_FILES
    main.cpp
    source/App.cpp
    source/Layer.cpp
    source/Texture.cpp
    source/Renderer.cpp
    source/Object.cpp
    source/Material.cpp
)

# Add header with path to resources and add header to include directory
set(INCLUDE_RESOURCES_STRING ${CMAKE_CURRENT_LIST_DIR}/resources)
configure_file(
    ${CMAKE_SOURCE_DIR}/resources/ResourcePath.h.in
    ${CMAKE_BINARY_DIR}/generated/ResourcePath.h @ONLY
)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/generated)

add_executable(Gamma ${SOURCE_FILES} ${HEADER_FILES})

enable_warnings(Gamma)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Gamma)
target_include_directories(Gamma PRIVATE include ${GLM_INCLUDE_DIR})

## target_link_libraries takes care of setting the include
target_link_libraries(Gamma PRIVATE OpenGL::GL glad::glad glfw stb::stb glm::glm imgui)
