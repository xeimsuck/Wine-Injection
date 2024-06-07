#ifndef AC_CLIENT_EXE_H
#define AC_CLIENT_EXE_H

#include <basetsd.h>

// module: ac_client.exe
namespace wine::mem::ac_client {
    // functions
    // description: contains all pointers to function
    namespace global {
        constexpr UINT_PTR pEntityPointersList = 0x191FCC;
    }
    namespace functions {
        constexpr UINT_PTR pEntityDamage = 0x1C130;
    }

    // class: entity
    // description: contains all data of entity
    // size: idk
    namespace entity {
        constexpr UINT_PTR fPositionX = 0x28;
        constexpr UINT_PTR fPositionY = 0x2C;
        constexpr UINT_PTR fPositionZ = 0x30;
        constexpr UINT_PTR fRadius = 0x48;
        constexpr UINT_PTR fCameraHeight = 0x50;
        constexpr UINT_PTR fMaxCameraHeight = 0x54;
        constexpr UINT_PTR iHealth = 0xEC;
        constexpr UINT_PTR iArmor = 0xF0;
        constexpr UINT_PTR iMK77Ammo  = 0x108;
        constexpr UINT_PTR iTMPAmmo  = 0x10C;
        constexpr UINT_PTR iAD81Ammo  = 0x118;
        constexpr UINT_PTR iMP3PAmmo = 0x11C;
        constexpr UINT_PTR iMTP57Ammo = 0x120;
        constexpr UINT_PTR iMK77Magazine = 0x12C;
        constexpr UINT_PTR iTMPMagazine  = 0x130;
        constexpr UINT_PTR iAD81Magazine  = 0x13C;
        constexpr UINT_PTR iMTP57Magazine = 0x140;
        constexpr UINT_PTR iGrenades = 0x144;
        constexpr UINT_PTR iFragsCount = 0x1DC;
        constexpr UINT_PTR iDeathsCount = 0x1E4;
    }
}

#endif //AC_CLIENT_EXE_H
