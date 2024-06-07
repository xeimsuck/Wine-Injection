#ifndef BINDS_H
#define BINDS_H

#include <string>

namespace wine::core {
    void inspectBinds();
    void loadBinds(const std::string& path);
}

#endif //BINDS_H
