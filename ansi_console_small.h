/** ansi_console_small.h made by William Dawson (MrBisquit on GitHub)
 *  GitHub:     https://github.com/MrBisquit/ansi_console
 *  File:       https://github.com/MrBisquit/ansi_console/tree/main/ansi_console_small.h
 *  License:    SPDX-License-Identifier: MIT
 *              See LICENSE file in the project root for full license text.
 */

#pragma once

#ifndef CONSOLE_H

/**
    Information on ANSI escape codes are available here:    https://gist.github.com/ConnerWill/d4b6c776b509add763e17f9f113fd25b
    See examples:                                           https://stackoverflow.com/a/54062826
    Truecolor:                                              https://en.wikipedia.org/wiki/Color_depth#True_color_.2824-bit.29
  
    Name            FG  BG
	Black           30  40
	Red             31  41
	Green           32  42
	Yellow          33  43
	Blue            34  44
	Magenta         35  45
	Cyan            36  46
	White           37  47
	Bright Black    90  100
	Bright Red      91  101
	Bright Green    92  102
	Bright Yellow   93  103
	Bright Blue     94  104
	Bright Magenta  95  105
	Bright Cyan     96  106
	Bright White    97  107

    This file uses the American spelling of colour (color).
*/

#pragma region // Definitions
// Color definitions
// Foreground
#define CONSOLE_FG_BLACK                30
#define CONSOLE_FG_RED                  31
#define CONSOLE_FG_GREEN                32
#define CONSOLE_FG_YELLOW               33
#define CONSOLE_FG_BLUE                 34
#define CONSOLE_FG_MAGENTA              35
#define CONSOLE_FG_CYAN                 36
#define CONSOLE_FG_WHITE                37
#define CONSOLE_FG_BRIGHT_BLACK         90
#define CONSOLE_FG_BRIGHT_RED           91
#define CONSOLE_FG_BRIGHT_GREEN         92
#define CONSOLE_FG_BRIGHT_YELLOW        93
#define CONSOLE_FG_BRIGHT_BLUE          94
#define CONSOLE_FG_BRIGHT_MAGENTA       95
#define CONSOLE_FG_BRIGHT_CYAN          96
#define CONSOLE_FG_BRIGHT_WHITE         97
// Background
#define CONSOLE_BG_BLACK                40
#define CONSOLE_BG_RED                  41
#define CONSOLE_BG_GREEN                42
#define CONSOLE_BG_YELLOW               43
#define CONSOLE_BG_BLUE                 44
#define CONSOLE_BG_MAGENTA              45
#define CONSOLE_BG_CYAN                 46
#define CONSOLE_BG_WHITE                47
#define CONSOLE_BG_BRIGHT_BLACK         100
#define CONSOLE_BG_BRIGHT_RED           101
#define CONSOLE_BG_BRIGHT_GREEN         102
#define CONSOLE_BG_BRIGHT_YELLOW        103
#define CONSOLE_BG_BRIGHT_BLUE          104
#define CONSOLE_BG_BRIGHT_MAGENTA       105
#define CONSOLE_BG_BRIGHT_CYAN          106
#define CONSOLE_BG_BRIGHT_WHITE         107

// Colors/Graphics mode
#define CONSOLE_GRAPHICS_RESET                  0
#define CONSOLE_GRAPHICS_BOLD                   1
#define CONSOLE_GRAPHICS_DIM                    2
#define CONSOLE_GRAPHICS_ITALIC                 3
#define CONSOLE_GRAPHICS_UNDERLINE              4
#define CONSOLE_GRAPHICS_BLINKING               5
#define CONSOLE_GRAPHICS_INVERSE_REVERSE        7
#define CONSOLE_GRAPHICS_HIDDEN_INVISIBLE       8
#define CONSOLE_GRAPHICS_STRIKETHROUGH          9
// Reset sequences
#define CONSOLE_GRAPHICS_RESET_BOLD             22
#define CONSOLE_GRAPHICS_RESET_DIM              22
#define CONSOLE_GRAPHICS_RESET_ITALIC           23
#define CONSOLE_GRAPHICS_RESET_UNDERLINE        24
#define CONSOLE_GRAPHICS_RESET_BLINKING         25
#define CONSOLE_GRAPHICS_RESET_INVERSE_REVERSE  27
#define CONSOLE_GRAPHICS_RESET_HIDDEN_INVISIBLE 28
#define CONSOLE_GRAPHICS_RESET_STRIKETHROUGH    29

// Screen modes
#define CONSOLE_MODE_40x25_MONOCHROME           0
#define CONSOLE_MODE_40x25_COLOR                1
#define CONSOLE_MODE_80x25_MONOCHROME           2
#define CONSOLE_MODE_80x25_COLOR                3
#define CONSOLE_MODE_320x200_4_COLOR            4
#define CONSOLE_MODE_320x200_MONOCHROME         5
#define CONSOLE_MODE_640x200_MONOCHROME         6
#define CONSOLE_MODE_LINE_WRAPPING              7      // I have no idea why this is in the middle of here and not at one end
#define CONSOLE_MODE_320x200_COLOR              13
#define CONSOLE_MODE_640x200_16_COLOR           14
#define CONSOLE_MODE_640x350_MONOCHROME         15
#define CONSOLE_MODE_640x350_16_COLOR           16
#define CONSOLE_MODE_640x480_MONOCHROME         17
#define CONSOLE_MODE_640x480_16_COLOR           18
#define CONSOLE_MODE_320x200_256_COLOR          19

#pragma endregion
#pragma region // Colors

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define CONSOLE_COLOR(color)        "\x1B[" STR(color) "%dm"
#define CONSOLE_COLOR_RESET         "\033[0m"
#define CONSOLE_COLOR_RGB_FG(r,g,b) "\x1B[38;2;" STR(r) ";" STR(g) ";" STR(b) "m"
#define CONSOLE_COLOR_RGB_BG(r,g,b) "\x1B[48;2;" STR(r) ";" STR(g) ";" STR(b) "m"

#define CONSOLE_CURSOR_RESET        "\x1B[H"
#define CONSOLE_CURSOR_MOVE(l,c)    "\x1B[" STR(l) ";" STR(c) "H\x1B[" STR(l) ";" STR(c) "f"

#define CONSOLE_SCREEN_CLEAR        "\x1B[2J"
#define CONSOLE_SCREEN_CLEAR_LINE   "\x1B[2K"

#define CONSOLE_GRAPHICS_SET(g)     "\x1B[" STR(g) "m"

#pragma region // Colors

#endif // CONSOLE_H