#include "hacks.hpp"

#include "../memory/game/ac_client.exe.hpp"

bool wine::hacks::isAlive(const UINT_PTR entity) {
    return *reinterpret_cast<int*>(entity+mem::ac_client::entity::iHealth)>0;
}
