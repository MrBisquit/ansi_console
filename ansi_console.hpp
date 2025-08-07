/** ansi_console.hpp made by William Dawson (MrBisquit on GitHub)
 *  GitHub:     https://github.com/MrBisquit/ansi_console
 *  File:       https://github.com/MrBisquit/ansi_console/tree/main/ansi_console.hpp
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

namespace Console {
    enum Color {
        Black           = 30,
        Red             = 31,
        Green           = 32,
        Yellow          = 33,
        Blue            = 34,
        Magenta         = 35,
        Cyan            = 36,
        White           = 37,

        Bright_Black    = 90,
        Bright_Red      = 91,
        Bright_Green    = 92,
        Bright_Yellow   = 93,
        Bright_Blue     = 94,
        Bright_Magenta  = 95,
        Bright_Cyan     = 96,
        Bright_White    = 97
    };

    enum GraphicsMode {
        Reset           = 0,
        Bold            = 1,
        Dim             = 2,
        Italic          = 3,
        Underline       = 4,
        Blinking        = 5,
        Reverse         = 7,
        Invisible       = 8,
        Strikethrough   = 9
    };

    enum ScreenMode {
        _40x25_MONOCHROME      = 0,
        _40x25_COLOR           = 1,
        _80x25_MONOCHROME      = 2,
        _80x25_COLOR           = 3,
        _320x200_4_COLOR       = 4,
        _320x200_MONOCHROME    = 5,
        _640x200_MONOCHROME    = 6,
        _LINE_WRAPPING         = 7,  // I have no idea why this is in the middle of here and not at one end
        _320x200_COLOR         = 13,
        _640x200_16_COLOR      = 14,
        _640x350_MONOCHROME    = 15,
        _640x350_16_COLOR      = 16,
        _640x480_MONOCHROME    = 17,
        _640x480_16_COLOR      = 18,
        _320x200_256_COLOR     = 19
    };

    /// @brief Sets the foreground color
    /// @param color The color
    void set_foreground_color(Color color) {
        printf("\x1B[%dm", (uint8_t)color);
    }

    /// @brief Sets the background color
    /// @param color The color
    void set_background_color(Color color) {
        printf("\x1B[%dm", ((uint8_t)color) + 10);
    }

    /// @brief Sets the foreground color with RGB (If your terminal supports Truecolor)
    /// @param r Red
    /// @param g Green
    /// @param b Blue
    void set_foreground_rgb(uint8_t r, uint8_t g, uint8_t b) {
        printf("\x1B[38;2;{%d};{%d};{%d}m", r, g, b);
    }

    /// @brief Sets the background color with RGB (If your terminal supports Truecolor)
    /// @param r Red
    /// @param g Green
    /// @param b Blue
    void set_background_rgb(uint8_t r, uint8_t g, uint8_t b) {
        printf("\x1B[48;2;{%d};{%d};{%d}m", r, g, b);
    }

    /// @brief Resets console color
    void reset_color() {
        printf("\033[0m");
    }

    /// @brief Sets the graphics mode
    /// @param mode The graphics mode
    void graphics_set(GraphicsMode mode) {
        printf("\x1B[%dm", (uint8_t)mode);
    }

    /// @brief Reset the graphics node
    /// @param mode The graphics mode
    void graphics_reset(GraphicsMode mode) {
        if(mode == GraphicsMode::Dim) {
            printf("\x1B[22m");
            return;
        }

        printf("\x1B[%dm", ((uint8_t)mode) + 21);
    }

    void mode_set(ScreenMode mode) {
        printf("\x1B[=%dh", (uint8_t)mode);
    }

    void mode_reset(ScreenMode mode) {
        printf("\x1B[=%dl", (uint8_t)mode);
    }

    /// @brief Console private modes
    namespace Private {
        /// @brief Sets the cursor to be invisible
        /// @note These are implemented in most terminals, but not all
        void cursor_invisible() {
            printf("\x1B[?25l");
        }

        /// @brief Sets the cursor to be visible
        /// @note These are implemented in most terminals, but not all
        void cursor_visible() {
            printf("\x1B[?25h");
        }

        /// @brief Restores the screen
        /// @note These are implemented in most terminals, but not all
        void screen_restore() {
            printf("\x1B[?47l");
        }

        /// @brief Saves the screen
        /// @note These are implemented in most terminals, but not all
        void screen_save() {
            printf("\x1B[?47h");
        }

        /// @brief Enables the alternate buffer
        /// @note These are implemented in most terminals, but not all
        void alternate_buffer_enable() {
            printf("\x1B[?1049l");
        }

        /// @brief Disables the alternate buffer
        /// @note These are implemented in most terminals, but not all
        void alternate_buffer_disable() {
            printf("\x1B[?1049h");
        }
    }
}

#endif // CONSOLE_H