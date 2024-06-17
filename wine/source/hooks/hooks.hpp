#ifndef HOOKS_H
#define HOOKS_H

#include "hookSwapBuffers.h"
#include "hookDamageEntity.hpp"

namespace wine::hooks {
    int initHooks();
    void destroyHooks();
}

#endif //HOOKS_H
