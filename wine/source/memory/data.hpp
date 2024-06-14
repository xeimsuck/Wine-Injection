#ifndef DATA_H
#define DATA_H
#include <vector>
#include <glm/glm.hpp>
#include "../core/base.hpp"

namespace wine::mem::data {
    namespace stuff {
        inline HMODULE hDll = nullptr;
        inline HMODULE hACClient = nullptr;
        inline UINT_PTR player = 0;
        inline UINT_PTR* pEntityList = nullptr;
        inline int* pEntityListSize = nullptr;
        inline glm::mat4* matView = nullptr;
    }
    namespace gui {
        inline bool isGUIInited = false;
        inline bool isMenuOpened = false;
    }
    namespace hacks {
        namespace esp {
            inline bool isESP = false;
            inline bool isESPLines = false;
            inline bool isESPBoxes = false;
            inline bool isESPHealths = false;
            inline bool isESPNames = false;
            inline glm::vec3 colorESP{255, 0, 0};
        }
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
