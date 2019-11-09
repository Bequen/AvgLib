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

#define FLOW_HORIZONTAL 0x0000
#define FLOW_VERTICAL 0x0001

class TerminalWindow {
    public:
        char* name;

        int32_t width, height;
        int32_t padding;

        TerminalWindow* children;
        uint32_t childCount;

        uint32_t flow;

        TerminalWindow() :
        width(0), height(0), padding(0), name(nullptr), children(nullptr), childCount(0) {

        }

        TerminalWindow(char* name, int32_t width, int32_t height, int32_t padding) :
        width(width), height(height), padding(padding), name(name), children(nullptr), childCount(0) {
            
        }



        void set_size(uint32_t width, uint32_t height) {
            this->width = width;
            this->height = height;
        }
};

class Terminal {
    public:
        int32_t requestDraw = 0;

        TerminalWindow frame;

        uint32_t width;
        uint32_t height;

        wchar_t* buffer;

        Terminal() {
            std::locale::global (std::locale ("en_US.UTF-8"));
            terminal_size_changed();
            frame.padding = 1;

            frame.children = new TerminalWindow[5];
            frame.childCount = 0;
            frame.children[frame.childCount++] = TerminalWindow(nullptr, 10, 10, 1);
            frame.children[frame.childCount++] = TerminalWindow(nullptr, 30, 10, 1);
        }

        void draw() {
            terminal_size_changed();

            if(requestDraw) {
                draw_window(frame, buffer, 0, 0);
                requestDraw = 0;

                std::wcout << buffer;
                std::flush(std::wcout);
            }
        }

        void terminal_size_changed() {
            struct winsize w;
            ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
            
            if(w.ws_row != frame.height || w.ws_col != frame.width) {
                on_terminal_size_change(w.ws_col, w.ws_row);
                requestDraw = true;
            }
        }

        void on_terminal_size_change(uint32_t width, uint32_t height) {
            this->frame.set_size(width, height);
            delete [] buffer;
            buffer = new wchar_t[width * height];
        }

        void create_window(TerminalWindow* parent, TerminalWindow window) {
            parent->children[parent->childCount++] = window;
            requestDraw = 1;
        }

        void draw_window(TerminalWindow window, wchar_t* buffer, uint32_t offsetX, uint32_t offsetY) {
            /* std::wcout << LEFT_TOP;
            int32_t passed = 0;

            for(uint32_t x = 0; x < window.width - 2; x++) {
                if(passed)
                    std::wcout << ROOF;
                else {
                    if(!window.name || window.name[x] == '\0') {
                        passed = 1;
                        std::wcout << ROOF;
                        continue;
                    }
                    std::wcout << INVERT << window.name[x] << REINVERT;
                }
            } std::wcout << RIGHT_TOP << "\n";

            for(uint32_t y = 0; y < window.height - 2; y++) {
                std::wcout << WALL;
                for(uint32_t x = 0; x < window.width - 2; x++)
                    std::wcout << " ";
                std::wcout << WALL << "\n";
            } 
            
            std::wcout << LEFT_BOTTOM;
            for(uint32_t x = 0; x < window.width - 2; x++) {
                std::wcout << ROOF;
            } std::wcout << RIGHT_BOTTOM;

            std::wcout << "\r" << CURSOR_UP(window.height - 2 - window.padding) << CURSOR_FORWARD(1 + window.padding * 2) << "pepik";
            std::flush(std::wcout); */

            uint32_t oX = offsetX;
            uint32_t oY = offsetY;

            buffer[offsetX + frame.width * offsetY] = LEFT_TOP;
            int32_t passed = 0;

            for(uint32_t x = 0; x < window.width - 2; x++) {
                if(passed)
                    buffer[++offsetX + frame.width * offsetY] = ROOF;
                else {
                    if(!window.name || window.name[x] == '\0') {
                        passed = 1;
                        buffer[++offsetX + frame.width * offsetY] = ROOF;
                        continue;
                    }
                    buffer[++offsetX + frame.width * offsetY] = window.name[x];
                }
            } 
            buffer[++offsetX + frame.width * offsetY] = RIGHT_TOP;

            
            for(uint32_t y = 0; y < window.height - 2; y++) {
                offsetX = oX;
                buffer[offsetX + frame.width * ++offsetY] = WALL;
                for(uint32_t x = 0; x < window.width - 2; x++)
                    buffer[++offsetX + frame.width * offsetY] = (wchar_t)' ';
                buffer[++offsetX + frame.width * offsetY] = WALL;
            } offsetX = oX;
            
            buffer[offsetX + frame.width * offsetY] = LEFT_BOTTOM;
            for(uint32_t x = 0; x < window.width - 2; x++) {
                buffer[++offsetX + frame.width * offsetY] = ROOF;
            } buffer[++offsetX + frame.width * offsetY] = RIGHT_BOTTOM;

            for(uint32_t i = 0; i < window.childCount; i++) {
                
                draw_window(window.children[i], buffer, oX, oY);
                
                if(window.flow == FLOW_HORIZONTAL) {
                    oX += window.children[i].width - 1;
                }
            }
        }
};