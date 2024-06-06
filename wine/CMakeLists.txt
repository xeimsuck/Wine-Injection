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
        source/gui/gui.h
        source/hooks/hookSwapBuffers.cpp
        source/hooks/hookSwapBuffers.h)

# MinHook
## link
target_include_directories(wine PRIVATE "lib/MinHook/include")
target_link_libraries(wine "${CMAKE_CURRENT_LIST_DIR}/lib/MinHook/lib/libMinHook.a")

# GLEW
## link
set(CMAKE_PREFIX_PATH "lib/GLEW/lib/cmake/glew")
find_package(glew CONFIG REQUIRED)
target_link_libraries(wine GLEW::glew_s)