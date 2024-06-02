# wine
## build wine
add_library(wine SHARED source/main.cpp
        source/core/base.cpp
        source/core/base.h
        source/memory/game/ac_client.exe.h
        source/memory/data.h
        source/hooks/hooks.cpp
        source/hooks/hooks.h)

# MinHook
## link MinHook
target_include_directories(wine PRIVATE "lib/MinHook/include")
target_link_libraries(wine "${CMAKE_CURRENT_LIST_DIR}/lib/MinHook/lib/libMinHook.a")
