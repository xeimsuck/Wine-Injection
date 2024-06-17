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
            inline bool isESPLines = true;
            inline bool isESPBoxes = true;
            inline bool isESPHealths = true;
            inline bool isESPNames = true;
            inline glm::vec3 colorESP{255, 0, 0};
        }
        namespace aimbot {
            inline UINT_PTR target = 0;
            inline bool isAimBot = false;
        }
        inline bool isGodMode = false;
        inline bool isInfinityAmmo = false;
        inline bool isInstantKill = false;
    }
    namespace binds {
        inline unsigned short bindKeyOpenMenu = VK_INSERT;
        inline unsigned short bindKeyESP = VK_F1;
        inline unsigned short bindKeyAimBot = VK_F2;
    }
}

#endif //DATA_H
