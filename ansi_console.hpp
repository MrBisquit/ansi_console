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
    enum Colors {
        Black           = 30,
        Red             = 31,
        Green           = 32,
        Yellow          = 33,
        Blue            = 34,
        Magenta         = 35,
        Cyan            = 36,
        White           = 37,

        Bright_Black,
        Bright_Green,
        Bright_Yellow,
        Bright_Blue,
        Bright_Magenta,
        Bright_Cyan,
        Bright_White
    };
}

#endif // CONSOLE_H