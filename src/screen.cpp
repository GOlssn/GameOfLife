/*
 * Autor       : Mikael Nilsson
 * Filename    : screen.cpp
 * Description : Collection of functions to draw in a console window. 
 * Version     : 0.2
 *
*/

#include "screen.h"
#include <cstring>
#include <algorithm>

#include <iostream>

void Screen::clear()
{
    fill(' ', TerminalColor());
}

void Screen::fill(char ch, const TerminalColor& color)
{
    memset(m_data, ch, m_size);
    std::fill(m_color, m_color+m_size, color);
}

void Screen::set(uint16_t x, uint16_t y, char ch, const TerminalColor &color)
{
    m_data[y*m_width + x] = ch;
    m_color[y*m_width + x] = color;
}

void Screen::fillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, char ch, const TerminalColor &color)
{
    uint32_t pos = y*m_width + x;
    for(int i = 0; i < h; i++)
    {
        uint32_t idx = + pos + i*m_width;
        memset(m_data + idx , ch, w);
        std::fill(m_color + idx, m_color + idx + w, color);
    }
}

void Screen::setText(uint16_t x, uint16_t y, const std::string &text, const TerminalColor &color)
{
    uint32_t pos = y*m_width + x;
    for(uint32_t i = 0; i < text.size(); i++)
    {
        m_data[pos + i] = text.at(i);
        m_color[pos + i] = color;
    }
}

void Screen::setTextRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const std::string &text, const TerminalColor &color)
{
    uint32_t pos = y*m_width + x;
    for(uint32_t i = 0; i < text.size(); i++)
    {
        if(i%w == 0 && i != 0)
        {
            pos += m_width - w;
            h--;
        }
        if(h == 0) break;
        m_data[pos + i] = text.at(i);
        m_color[pos + i] = color;
    }
}

void Screen::draw(Terminal &terminal)
{
    terminal.clear();
    for(uint16_t y = 0; y < m_height; y++)
    {
        for(uint16_t x = 0; x < m_width; x++)
        {
            terminal.pushColor(m_color[y*m_width + x]);
            std::cout << m_data[y*m_width + x];
            terminal.popColor();
        }
        std::cout << "\n";
    }
    std::cout << std::flush;
}
