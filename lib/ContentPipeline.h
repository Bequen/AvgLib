#pragma once

namespace avg {
    /**
     * @brief  Contains useful functions that works with files
     * @note   
     */
    namespace ContentPipeline {
        /**
         * @brief  Loads all the text from specified file
         * @note   Does not return length
         * @param  path: path to the file
         * @retval Returns actual text
         */
        char* loadText(const char* path);
    };
};