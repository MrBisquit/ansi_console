/** ansi_console_small.h made by William Dawson (MrBisquit on GitHub)
 *  GitHub:     https://github.com/MrBisquit/ansi_console
 *  File:       https://github.com/MrBisquit/ansi_console/tree/main/ansi_console_small.h
 *  License:    SPDX-License-Identifier: MIT
 *              See LICENSE file in the project root for full license text.
 */

#pragma once
#include <stdio.h>
#include <stdint.h>

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
#define CONSOLE_FG_BLACK                (uint8_t)30
#define CONSOLE_FG_RED                  (uint8_t)31
#define CONSOLE_FG_GREEN                (uint8_t)32
#define CONSOLE_FG_YELLOW               (uint8_t)33
#define CONSOLE_FG_BLUE                 (uint8_t)34
#define CONSOLE_FG_MAGENTA              (uint8_t)35
#define CONSOLE_FG_CYAN                 (uint8_t)36
#define CONSOLE_FG_WHITE                (uint8_t)37
#define CONSOLE_FG_BRIGHT_BLACK         (uint8_t)90
#define CONSOLE_FG_BRIGHT_RED           (uint8_t)91
#define CONSOLE_FG_BRIGHT_GREEN         (uint8_t)92
#define CONSOLE_FG_BRIGHT_YELLOW        (uint8_t)93
#define CONSOLE_FG_BRIGHT_BLUE          (uint8_t)94
#define CONSOLE_FG_BRIGHT_MAGENTA       (uint8_t)95
#define CONSOLE_FG_BRIGHT_CYAN          (uint8_t)96
#define CONSOLE_FG_BRIGHT_WHITE         (uint8_t)97
// Background
#define CONSOLE_BG_BLACK                (uint8_t)40
#define CONSOLE_BG_RED                  (uint8_t)41
#define CONSOLE_BG_GREEN                (uint8_t)42
#define CONSOLE_BG_YELLOW               (uint8_t)43
#define CONSOLE_BG_BLUE                 (uint8_t)44
#define CONSOLE_BG_MAGENTA              (uint8_t)45
#define CONSOLE_BG_CYAN                 (uint8_t)46
#define CONSOLE_BG_WHITE                (uint8_t)47
#define CONSOLE_BG_BRIGHT_BLACK         (uint8_t)100
#define CONSOLE_BG_BRIGHT_RED           (uint8_t)101
#define CONSOLE_BG_BRIGHT_GREEN         (uint8_t)102
#define CONSOLE_BG_BRIGHT_YELLOW        (uint8_t)103
#define CONSOLE_BG_BRIGHT_BLUE          (uint8_t)104
#define CONSOLE_BG_BRIGHT_MAGENTA       (uint8_t)105
#define CONSOLE_BG_BRIGHT_CYAN          (uint8_t)106
#define CONSOLE_BG_BRIGHT_WHITE         (uint8_t)107

// Colors/Graphics mode
#define CONSOLE_GRAPHICS_RESET                  (uint8_t)0
#define CONSOLE_GRAPHICS_BOLD                   (uint8_t)1
#define CONSOLE_GRAPHICS_DIM                    (uint8_t)2
#define CONSOLE_GRAPHICS_ITALIC                 (uint8_t)3
#define CONSOLE_GRAPHICS_UNDERLINE              (uint8_t)4
#define CONSOLE_GRAPHICS_BLINKING               (uint8_t)5
#define CONSOLE_GRAPHICS_INVERSE_REVERSE        (uint8_t)7
#define CONSOLE_GRAPHICS_HIDDEN_INVISIBLE       (uint8_t)8
#define CONSOLE_GRAPHICS_STRIKETHROUGH          (uint8_t)9
// Reset sequences
#define CONSOLE_GRAPHICS_RESET_BOLD             (uint8_t)22
#define CONSOLE_GRAPHICS_RESET_DIM              (uint8_t)22
#define CONSOLE_GRAPHICS_RESET_ITALIC           (uint8_t)23
#define CONSOLE_GRAPHICS_RESET_UNDERLINE        (uint8_t)24
#define CONSOLE_GRAPHICS_RESET_BLINKING         (uint8_t)25
#define CONSOLE_GRAPHICS_RESET_INVERSE_REVERSE  (uint8_t)27
#define CONSOLE_GRAPHICS_RESET_HIDDEN_INVISIBLE (uint8_t)28
#define CONSOLE_GRAPHICS_RESET_STRIKETHROUGH    (uint8_t)29

// Screen modes
#define CONSOLE_MODE_40x25_MONOCHROME           (uint8_t)0
#define CONSOLE_MODE_40x25_COLOR                (uint8_t)1
#define CONSOLE_MODE_80x25_MONOCHROME           (uint8_t)2
#define CONSOLE_MODE_80x25_COLOR                (uint8_t)3
#define CONSOLE_MODE_320x200_4_COLOR            (uint8_t)4
#define CONSOLE_MODE_320x200_MONOCHROME         (uint8_t)5
#define CONSOLE_MODE_640x200_MONOCHROME         (uint8_t)6
#define CONSOLE_MODE_LINE_WRAPPING              (uint8_t)7      // I have no idea why this is in the middle of here and not at one end
#define CONSOLE_MODE_320x200_COLOR              (uint8_t)13
#define CONSOLE_MODE_640x200_16_COLOR           (uint8_t)14
#define CONSOLE_MODE_640x350_MONOCHROME         (uint8_t)15
#define CONSOLE_MODE_640x350_16_COLOR           (uint8_t)16
#define CONSOLE_MODE_640x480_MONOCHROME         (uint8_t)17
#define CONSOLE_MODE_640x480_16_COLOR           (uint8_t)18
#define CONSOLE_MODE_320x200_256_COLOR          (uint8_t)19

#pragma endregion
#pragma region // Colors

#define CONSOLE_COLOR(color)        "\x1B[" color "%dm"
#define CONSOLE_COLOR_RESET         "\033[0m"
#define CONSOLE_COLOR_RGB_FG(r,g,b) "\x1B[38;2;" r ";" g ";" b "m"
#define CONSOLE_COLOR_RGB_BG(r,g,b) "\x1B[48;2;" r ";" g ";" b "m"

#define CONSOLE_CURSOR_RESET        "\x1B[H"
#define CONSOLE_CURSOR_MOVE(l,c)    "\x1B[" l ";" c "H\x1B[" l ";" c "f"

#define CONSOLE_SCREEN_CLEAR        "\x1B[2J"
#define CONSOLE_SCREEN_CLEAR_LINE   "\x1B[2K"

#define CONSOLE_GRAPHICS_SET(g)     "\x1B[" g "m"

#define CONSOLE_MODE_SET(m)         "\x1B[=" m "h"
#define CONSOLE_MODE_RESET(m)       "\x1B[=" m "l"

#pragma region // Colors

#endif // CONSOLE_H