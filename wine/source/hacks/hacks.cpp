#include "hacks.hpp"

#include <string>
#include <glm/glm.hpp>
#include "memory/game/ac_client.exe.hpp"
#include "memory/data.hpp"

bool wine::hacks::isAlive(const UINT_PTR entity) {
    return getHealth(entity)>0;
}

int wine::hacks::getHealth(const UINT_PTR entity) {
    return *reinterpret_cast<int*>(entity+mem::ac_client::entity::iHealth);
}

float wine::hacks::findDistance(const UINT_PTR entity1, const UINT_PTR entity2) {
    return glm::length(findDistanceVector(entity1, entity2));
}

glm::vec3 wine::hacks::findDistanceVector(const UINT_PTR from, const UINT_PTR to) {
    const glm::vec3 frompos = *reinterpret_cast<glm::vec3*>(from+mem::ac_client::entity::fPositionX);
    const glm::vec3 topos = *reinterpret_cast<glm::vec3*>(to+mem::ac_client::entity::fPositionX);
    return topos-frompos;
}



UINT_PTR wine::hacks::findAimbotTarget() {
    if(!isAlive(mem::data::stuff::player)) return 0;
    const UINT_PTR entityList = *mem::data::stuff::pEntityList;

    UINT_PTR nearbyTarget = 0;
    float nearbyDistance = INT_MAX;

    for(int i = 0; i < *mem::data::stuff::pEntityListSize; ++i) {
        const UINT_PTR entityAddress = *reinterpret_cast<UINT*>(entityList+sizeof(UINT_PTR)*i);
        if(!isAlive(entityAddress)) continue;
        const float distance = findDistance(mem::data::stuff::player, entityAddress);
        if(distance<nearbyDistance) {
            nearbyDistance = distance;
            nearbyTarget = entityAddress;
        }
    }

    return nearbyTarget;
}



void wine::hacks::aimbot() {
    if(!mem::data::hacks::aimbot::target) return;
    const glm::vec3 direction = glm::normalize(findDistanceVector(mem::data::stuff::player, mem::data::hacks::aimbot::target));
    float& yaw = *reinterpret_cast<float*>(mem::data::stuff::player+mem::ac_client::entity::fYaw);
    float& pitch = *reinterpret_cast<float*>(mem::data::stuff::player+mem::ac_client::entity::fPitch);
    pitch = glm::degrees(std::asin(direction.z));
    yaw = glm::degrees(std::asin(direction.x/std::sqrt(direction.x*direction.x+direction.y*direction.y)));
    if(direction.y>0) yaw = 540-yaw;
}

