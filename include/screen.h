/*
 * Autor       : Mikael Nilsson
 * Filename    : screen.h
 * Description : Collection of functions to draw in a console window. 
 * Version     : 0.2
 *
*/

#ifndef SCREEN
#define SCREEN

#include "terminal.h"
#include <cstdint>
#include <string>

class Screen {
public:
    Screen(uint16_t width, uint16_t height)
        : m_width(width), m_height(height),
          m_size(width*height), m_color(new TerminalColor[m_size]),
          m_data(new char[m_size])
    {}

    ~Screen() {
        delete[] m_color;
        delete[] m_data;

        m_color = NULL;
        m_data = NULL;
    }

    void clear();
    void fill(char ch, const TerminalColor &color);
    void fillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, char ch, const TerminalColor &color);
    void set(uint16_t x, uint16_t y, char ch, const TerminalColor &color);
    void setText(uint16_t x, uint16_t y, const std::string& text,  const TerminalColor &color);
    void setTextRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const std::string& text,  const TerminalColor &color);
    void draw(Terminal &terminal);
private:
    const uint16_t m_width;
    const uint16_t m_height;
    const uint32_t m_size;
    TerminalColor *m_color;
    char *m_data;
};

#endif // SCREEN

