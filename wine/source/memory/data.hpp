#ifndef DATA_H
#define DATA_H
#include <vector>
#include "../core/base.hpp"

namespace wine::mem::data {
    namespace stuff {
        inline HMODULE hDll = nullptr;
        inline HMODULE hACClient = nullptr;
        inline UINT_PTR pPlayer = 0;
        inline UINT_PTR* pEntityList = nullptr;
        inline int* pEntityListSize = nullptr;
    }
    namespace gui {
        inline bool isGUIInited = false;
        inline bool isMenuOpened = false;
    }
    namespace hacks {
        inline bool isVisualHack = false;
        inline bool isGodMode = false;
        inline bool isInfinityAmmo = false;
        inline bool isInstantKill = false;
        inline bool isAimBot = false;
    }
    namespace binds {
        inline unsigned short bindKeyOpenMenu = VK_INSERT;
    }
}

#endif //DATA_H
