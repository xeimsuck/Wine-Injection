# wine
## build wine
add_library(wine SHARED source/main.cpp
        source/core/base.cpp
        source/core/base.hpp
        source/memory/game/ac_client.exe.hpp
        source/memory/data.hpp
        source/hooks/hooks.cpp
        source/hooks/hooks.hpp
        source/gui/gui.cpp
        source/gui/gui.hpp
        source/hooks/hookSwapBuffers.cpp
        source/hooks/hookSwapBuffers.h
        source/core/binds.cpp
        source/core/binds.hpp
        source/gui/shader.cpp
        source/gui/shader.hpp
        source/shaders/shaderESPBox.hpp
        source/hacks/hacks.cpp
        source/hacks/hacks.hpp
        source/shaders/shaders.hpp
        source/shaders/shaderESPLine.hpp
        source/shaders/shaderESPHealth.hpp
)

# MinHook
## link
target_include_directories(wine PRIVATE "lib/MinHook/include")
target_link_libraries(wine "${CMAKE_CURRENT_LIST_DIR}/lib/MinHook/lib/libMinHook.a")

# GLEW
## link
set(CMAKE_PREFIX_PATH "lib/GLEW/lib/cmake/glew")
find_package(glew CONFIG REQUIRED)
target_link_libraries(wine GLEW::glew_s)

# GLM
## link
target_include_directories(wine PRIVATE "lib/GLM/include")

# ImGui
## Build
file(GLOB_RECURSE ImGui_SOURCE
        "lib/ImGui/*.h"
        "lib/ImGui/*.cpp"
)
add_library(ImGui STATIC ${ImGui_SOURCE})
## Link
target_include_directories(wine PRIVATE "lib/ImGui")
target_link_libraries(ImGui Dwmapi.lib)
target_link_libraries(wine ImGui)
