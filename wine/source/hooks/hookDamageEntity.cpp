#include "hookDamageEntity.hpp"
#include <windows.h>
#include <MinHook.h>
#include "memory/data.hpp"
#include "hacks/hacks.hpp"
#include "memory/game/ac_client.exe.hpp"

void (*trampolineDamageFunction)() = nullptr;

void detouredDamageEntity() {
    if(wine::mem::data::hacks::isGodMode) {
        UINT_PTR entity = 0;
        asm ("movl %%esi, %0": "=r"(entity));
        if(entity==wine::mem::data::stuff::player) asm ("ret $8"); // If Entity==Player => return
    }
    trampolineDamageFunction();
}
int wine::hooks::createHookDamageEntity() {
    return MH_CreateHook(reinterpret_cast<LPVOID>(reinterpret_cast<UINT_PTR>(wine::mem::data::stuff::hACClient)+wine::mem::ac_client::functions::pEntityDamage),
                         reinterpret_cast<LPVOID>(detouredDamageEntity), reinterpret_cast<LPVOID*>(&trampolineDamageFunction));
}

void wine::hooks::enableHookDamageEntity() {
    if(MH_EnableHook(reinterpret_cast<LPVOID>(reinterpret_cast<UINT_PTR>(wine::mem::data::stuff::hACClient)+wine::mem::ac_client::functions::pEntityDamage))!=MH_OK) MessageBoxW(nullptr, L"da", L"dwa", MB_OK);
}

void wine::hooks::disableHookDamageEntity() {
    MH_DisableHook(reinterpret_cast<LPVOID>(SwapBuffers));
}

void wine::hooks::removeHookDamageEntity() {
    MH_RemoveHook(reinterpret_cast<LPVOID>(SwapBuffers));
}