#pragma once

#include <cstdint>
#include <sys/stat.h>
#include <sys/types.h>

namespace avg
{
    /**
     * @brief  Namespace containing interface for working with files
     */
    namespace File
    {
    };

    /**
     * @brief  Allows you to check wheter the file was changed
     * @note   You have to manage checking yourself
     */
    class FileWatcher
    {
        public:
            char *path;       // Path to the file that is being watched
            time_t lastCheck; // Last time file change was detected

            /**
             * @brief  Creates new FileWatcher instance
             * @param  path[]: Path to the file that will be watched
             */
            FileWatcher(char path[]);

            /**
             * @brief  Checks for file change time
             * @retval Returns true if file was changed from last check
             */
            bool check();
    };
}; 