/** ansi_console.h made by William Dawson (MrBisquit on GitHub)
 *  GitHub:     https://github.com/MrBisquit/ansi_console
 *  File:       https://github.com/MrBisquit/ansi_console/tree/main/ansi_console.h
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

/// @brief This can set both the foreground and background color
/// @param color The color (definitions beginning with `CONSOLE_FG` or `CONSOLE_BG`)
void console_set_color(uint8_t color) {
    printf("\x1B[%dm", color);
}

/// @brief Set the console foreground color with RGB (If your terminal supports Truecolor)
/// @param r Red
/// @param g Green
/// @param b Blue
void console_set_foreground_rgb(uint8_t r, uint8_t g, uint8_t b) {
    printf("\x1B[38;2;{%d};{%d};{%d}m", r, g, b);
}

/// @brief Set the console background color with RGB (If your terminal supports Truecolor)
/// @param r Red
/// @param g Green
/// @param b Blue
void console_set_background_rgb(uint8_t r, uint8_t g, uint8_t b) {
    printf("\x1B[48;2;{%d};{%d};{%d}m", r, g, b);
}

/// @brief Resets console color
void console_reset_color() {
    printf("\033[0m");
}

/// @brief Resets the console cursor back to (0,0)
void console_reset_cursor() {
    printf("\x1B[H");
}

/// @brief Moves the console cursor to the specified line and column
/// @param line The line to move the console cursor to
/// @param column The column to move the console cursor to
void console_move_cursor(int line, int column) {
    printf("\x1B[%d;%dH", line, column);
    printf("\x1B[%d;%df", line, column);
}

/// @brief Clears the screen
void console_clear_screen() {
    printf("\x1B[2J");
}

/// @brief Clears the current line
/// @note You may want to move the cursor to the start of the line with `\r`
void console_clear_line() {
    printf("\x1B[2K");
}

/// @brief Sets the graphics mode
/// @param graphics The graphics mode (definitions beginning with `CONSOLE_GRPAHICS`)
void console_graphics_set(uint8_t graphics) {
    printf("\x1B[%dm", graphics);
}

/// @brief Sets the console screen mode
/// @param mode The console screen mode (definitions beginning with `CONSOLE_MODE`)
void console_mode_set(uint8_t mode) {
    printf("\x1B[=%dh", mode);
}

/// @brief Resets the console screen mode by using the same values as setting does
/// @param mode The console screen mode (definitions beginning with `CONSOLE_MODE`)
void console_mode_reset(uint8_t mode) {
    printf("\x1B[=%dl", mode);
}

// Console private modes
/// @brief Sets the cursor to be invisible
/// @note These are implemented in most terminals, but not all
void console_private_cursor_invisible() {
    printf("\x1B[?25l");
}

/// @brief Sets the cursor to be visible
/// @note These are implemented in most terminals, but not all
void console_private_cursor_visible() {
    printf("\x1B[?25h");
}

/// @brief Restores the screen
/// @note These are implemented in most terminals, but not all
void console_private_screen_restore() {
    printf("\x1B[?47l");
}

/// @brief Saves the screen
/// @note These are implemented in most terminals, but not all
void console_private_screen_save() {
    printf("\x1B[?47h");
}

/// @brief Enables the alternate buffer
/// @note These are implemented in most terminals, but not all
void console_private_alternate_buffer_enable() {
    printf("\x1B[?1049l");
}

/// @brief Disables the alternate buffer
/// @note These are implemented in most terminals, but not all
void console_private_alternate_buffer_disable() {
    printf("\x1B[?1049h");
}

#endif // CONSOLE_H