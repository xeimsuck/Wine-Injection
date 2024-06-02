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
## build MinHook
add_library(MinHook STATIC lib/MinHook/include/MinHook.h
        lib/MinHook/src/hde/hde32.c lib/MinHook/src/hde/hde32.h
        lib/MinHook/src/hde/hde64.c lib/MinHook/src/hde/hde64.h
        lib/MinHook/src/hde/pstdint.h
        lib/MinHook/src/hde/table32.h
        lib/MinHook/src/hde/table64.h
        lib/MinHook/src/buffer.c
        lib/MinHook/src/buffer.h
        lib/MinHook/src/hook.c
        lib/MinHook/src/trampoline.c
        lib/MinHook/src/trampoline.h)

## link MinHook
target_include_directories(wine PRIVATE "lib/MinHook/include")
target_link_libraries(wine MinHook)
