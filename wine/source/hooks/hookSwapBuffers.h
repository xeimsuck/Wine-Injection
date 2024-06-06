#ifndef HOOKSWAPBUFFERS_H
#define HOOKSWAPBUFFERS_H

namespace wine::hooks {
    int createHookSwapBuffers();
    void removeHookSwapBuffers();
    void enableHookSwapBuffers();
    void disableHookSwapBuffers();
}

#endif //HOOKSWAPBUFFERS_H
