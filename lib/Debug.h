#pragma once

#if __MINGW32__
    #include <stdio.h>
    #include <wchar.h>
    #include <windows.h>
#endif

#include <iostream>

#if __linux__
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif

#include "ASCII.h"

#define FOREGROUND_BLACK    "\033[0;30m"
#define FOREGROUND_RED      "\033[0;31m"
#define FOREGROUND_GREEN    "\033[0;32m"
#define FOREGROUND_YELLOW   "\033[0;33m"
#define FOREGROUND_BLUE     "\033[0;34m"
#define FOREGROUND_MAGENTA  "\033[0;35m"
#define FOREGROUND_CYAN     "\033[0;36m"
#define FOREGROUND_WHITE    "\033[0;37m"

#define BACKGROUND_BLACK    "\033[0;40m"
#define BACKGROUND_RED      "\033[0;41m"
#define BACKGROUND_GREEN    "\033[0;42m"
#define BACKGROUND_YELLOW   "\033[0;43m"
#define BACKGROUND_BLUE     "\033[0;44m"
#define BACKGROUND_MAGENTA  "\033[0;45m"
#define BACKGROUND_CYAN     "\033[0;46m"
#define BACKGROUND_WHITE    "\033[0;47m"

#define BOLD                "\033[1m"
#define RESET               "\033[0"
#define INVERT              "\033[7m"
#define REINVERT              "\033[27m"

#define CURSOR_UP(n)        "\033[" << n << "A"
#define CURSOR_DOWN(n)      "\033[" << n << "B"
#define CURSOR_FORWARD(n)   "\033[" << n << "C"
#define CURSOR_BACK(n)      "\033[" << n << "D"
#define CURSOR_POSITION(x,y)"\033[" << y << ";" << x << "H"

#define CURSOR_SHOW         "\033[25h"
#define CURSOR_HIDE         "\033[25l"

#define ERROR(message) std::cout << FOREGROUND_RED << BOLD << INVERT << "[ERROR]" << RESET << FOREGROUND_RED << ": " << message << FOREGROUND_WHITE << std::endl;
#define WARNING(message) std::cout << FOREGROUND_YELLOW << BOLD << INVERT << "[WARNING]" << RESET << FOREGROUND_YELLOW << ": " << message << FOREGROUND_WHITE << std::endl;
#define MESSAGE(message) std::cout << FOREGROUND_BLUE << BOLD << INVERT << "[MESSAGE]" << RESET << FOREGROUND_BLUE << ": " << message << FOREGROUND_WHITE << std::endl;
#define SUCCESS(message) std::cout << FOREGROUND_GREEN << BOLD << INVERT << "[SUCCESS]" << RESET << FOREGROUND_GREEN << ": " << message << FOREGROUND_WHITE << std::endl;

/**
 * @brief  There might be some things to get ready
 * @note   It allows default window's console to display colors
 * @retval None
 */
inline void debug_init() {
    #if __MINGW32__
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
        std::cout << "Couldn't initialize Debug Interface. Invalid output handle!" << std::endl;
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
        std::cout << "Unable to get console mode" << std::endl;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
        std::cout << "Unable to set console mode" << std::endl;
    #endif
}

class TerminalWindow {
    public:
        char* name;

        int32_t width, height;
        int32_t padding;

        TerminalWindow() :
        width(0), height(0), padding(0), name(nullptr) {

        }

        TerminalWindow(char* name, int32_t width, int32_t height, int32_t padding) :
        width(width), height(height), padding(padding) {
            this->name = name;
        }
};

class Terminal {
    public:
        int32_t requestDraw = 0;

        TerminalWindow* windows;
        uint32_t windowCount;

        uint32_t width;
        uint32_t height;

        Terminal() {
            std::locale::global (std::locale ("en_US.UTF-8"));

            windows = new TerminalWindow[10];
            windowCount = 0;
            create_window(TerminalWindow("test", 35, 10, 1));
        }

        void draw() {
            terminal_size_changed();

            if(requestDraw) {
                for(uint32_t i = 0; i < windowCount; i++) {
                    draw_window(windows[i]);
                }
                requestDraw = 0;
            }
        }

        void terminal_size_changed() {
            struct winsize w;
            ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
            
            if(w.ws_row != height || w.ws_col != width) {
                on_terminal_size_change();
            }
        }

        void on_terminal_size_change() {

        }

        void create_window(TerminalWindow window) {
            windows[windowCount++] = window;
            requestDraw = 1;
        }

        void draw_window(TerminalWindow window) {
            std::wcout << LEFT_TOP;
            int32_t passed = 0;

            for(uint32_t x = 0; x < window.width; x++) {
                if(passed)
                    std::wcout << ROOF;
                else {
                    if(window.name[x] == '\0') {
                        passed = 1;
                        std::wcout << ROOF;
                        continue;
                    }
                    std::wcout << INVERT << window.name[x] << REINVERT;
                }
            } std::wcout << RIGHT_TOP << "\n";

            for(uint32_t y = 0; y < window.height; y++) {
                std::wcout << WALL;
                for(uint32_t x = 0; x < window.width; x++)
                    std::wcout << " ";
                std::wcout << WALL << "\n";
            } 
            
            std::wcout << LEFT_BOTTOM;
            for(uint32_t x = 0; x < window.width; x++) {
                std::wcout << ROOF;
            } std::wcout << RIGHT_BOTTOM << std::endl;

            std::wcout << CURSOR_UP(window.height + 1 - window.padding) << CURSOR_FORWARD(1 + window.padding) << "pepik";
            std::flush(std::wcout);
        }
};