#pragma once

#include <cstdint>
#include <sys/stat.h>
#include <sys/types.h>
#include "StringLib.h"

#if __WIN32__ || __MINGW32__
    #define DIRECTORY_SEPARATOR '\\'
#elif __linux__
    #define DIRECTORY_SEPARATOR '/'
#endif

namespace avg
{
    /**
     * @brief  Namespace containing interface for working with files
     */
    namespace File
    {
        #if __linux__
        inline char* get_home_dir() {

        }
        #endif

        #if __MINGW32__ || __WIN32__
        inline char* get_appdata_dir() {
            return getenv("APPDATA");
        }
        #endif

        namespace Dir {
            char* go_back_cpy(char* path) {
                char* result = new char[StringLib::length(path)];
                
                for(uint32_t i = StringLib::length(path); i >= 0; i--) {
                    if(path[i] == DIRECTORY_SEPARATOR) {
                        memcpy(result, path, i);
                        result[i] = '\0';

                        break;
                    }
                }

                return result;
            }

            void go_back(char* path) {
                for(uint32_t i = StringLib::length(path); i >= 0; i--) {
                    if(path[i] == DIRECTORY_SEPARATOR) {
                        path[i] = '\0';
                        break;
                    }
                }
            }
        };
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