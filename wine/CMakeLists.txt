add_library(wine SHARED source/main.cpp
        source/core/base.cpp
        source/core/base.h
        source/memory/game/ac_client.exe.h
        source/memory/data.h
        source/hooks/hooks.cpp
        source/hooks/hooks.h)