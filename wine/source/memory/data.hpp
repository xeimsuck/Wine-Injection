#ifndef DATA_H
#define DATA_H
#include "../core/base.hpp"

namespace wine::mem::data {
    namespace stuff {
        inline HMODULE hDll = nullptr;
        inline HMODULE hACClient = nullptr;
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
        inline unsigned short openMenu = VK_INSERT;
    }
}

#endif //DATA_H
