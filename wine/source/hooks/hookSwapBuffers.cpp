#include "hookSwapBuffers.h"
#include <windows.h>
#include <MinHook.h>
#include "../gui/gui.h"

WINBOOL WINAPI (*tramplineSwapBuffers)(HDC) = nullptr;

WINBOOL WINAPI detouredSwapBuffers(HDC hDС) {
    wine::gui::draw();
    return tramplineSwapBuffers(hDС);
}

int wine::hooks::createHookSwapBuffers() {
    return MH_CreateHook(reinterpret_cast<LPVOID>(SwapBuffers), reinterpret_cast<LPVOID>(detouredSwapBuffers), reinterpret_cast<LPVOID*>(&tramplineSwapBuffers));
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
