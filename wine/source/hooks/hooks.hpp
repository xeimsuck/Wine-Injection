#ifndef HOOKS_H
#define HOOKS_H

#include "hookSwapBuffers.h"

namespace wine::hooks {
    int initHooks();
    void destroyHooks();
}

#endif //HOOKS_H
