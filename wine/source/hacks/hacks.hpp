#ifndef HACKS_HPP
#define HACKS_HPP

#include <glm/vec3.hpp>
#include <basetsd.h>

namespace wine::hacks {
    bool isAlive(UINT_PTR entity);
    int getHealth(UINT_PTR entity);
    float findDistance(UINT_PTR entity1, UINT_PTR entity2);
    glm::vec3 findDistanceVector(UINT_PTR from, UINT_PTR to);
    UINT_PTR findAimbotTarget();
    void aimbot();
}

#endif //HACKS_HPP
