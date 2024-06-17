#include "hookSwapBuffers.h"
#include <windows.h>
#include <MinHook.h>
#include "gui/gui.hpp"
#include "memory/data.hpp"
#include "hacks/hacks.hpp"

WINBOOL WINAPI (*trampolineSwapBuffers)(HDC) = nullptr;

WINBOOL WINAPI detouredSwapBuffers(HDC hDС) {
    if(wine::mem::data::hacks::aimbot::isAimBot) wine::hacks::aimbot();
    wine::gui::draw();
    return trampolineSwapBuffers(hDС);
}

int wine::hooks::createHookSwapBuffers() {
    return MH_CreateHook(reinterpret_cast<LPVOID>(SwapBuffers), reinterpret_cast<LPVOID>(detouredSwapBuffers), reinterpret_cast<LPVOID*>(&trampolineSwapBuffers));
}

void wine::hooks::enableHookSwapBuffers() {
    MH_EnableHook(reinterpret_cast<LPVOID>(SwapBuffers));
}

void wine::hooks::disableHookSwapBuffers() {
    MH_DisableHook(reinterpret_cast<LPVOID>(SwapBuffers));
}

void wine::hooks::removeHookSwapBuffers() {
    MH_RemoveHook(reinterpret_cast<LPVOID>(SwapBuffers));
}
