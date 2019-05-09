#pragma once

#include <cstdint>
#include <sys/stat.h>
#include <sys/types.h>

namespace avg {
    namespace File {
        class FileWatcher {
            public:
                char* path;
                time_t lastCheck;

                FileWatcher(char path[]);
                bool check();
        };
    };
};