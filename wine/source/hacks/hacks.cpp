#include "hacks.hpp"

#include "../memory/game/ac_client.exe.hpp"

bool wine::hacks::isAlive(const UINT_PTR entity) {
    return getHealth(entity)>0;
}

int wine::hacks::getHealth(const UINT_PTR entity) {
    return *reinterpret_cast<int*>(entity+mem::ac_client::entity::iHealth);
}
