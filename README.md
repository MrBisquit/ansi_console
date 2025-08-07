# ANSI Console
A header-only library for using ANSI console escape codes, it is currently only available as a C header file, but I plan on making a C++ version soon.

<img src="https://badgen.net/github/license/MrBisquit/ansi_console" />
<img src="https://badgen.net/github/watchers/MrBisquit/ansi_console" />
<img src="https://badgen.net/github/stars/MrBisquit/ansi_console" />
<img src="https://badgen.net/github/forks/MrBisquit/ansi_console" />
<img src="https://badgen.net/github/contributors/MrBisquit/ansi_console" />
<img src="https://badgen.net/github/issues/MrBisquit/ansi_console" />
<img src="https://badgen.net/github/commits/MrBisquit/ansi_console" />
<img src="https://badgen.net/github/last-commit/MrBisquit/ansi_console" />
<img src="https://badgen.net/github/dependabot/MrBisquit/ansi_console" />

## Usage

> [!NOTE]
> When using a stream (`FILE*`), you must put `f` on the beginning of the function name,
> and prepend the file stream in the arguments.
> For example, instead of `console_set_color(color)`, use `fconsole_set_color(stream, color)`.

### C version
Copy the `ansi_console.h` file to your project, and import it.

#### Colours
These are the colour definitions.

| Colour  | Foreground           | Background           |
| :------ | :------------------- | :------------------- |
| Black   | `CONSOLE_FG_BLACK`   | `CONSOLE_BG_BLACK`   |
| Red     | `CONSOLE_FG_RED`     | `CONSOLE_BG_RED`     |
| Green   | `CONSOLE_FG_GREEN`   | `CONSOLE_BG_GREEN`   |
| Yellow  | `CONSOLE_FG_YELLOW`  | `CONSOLE_BG_YELLOW`  |
| Blue    | `CONSOLE_FG_BLUE`    | `CONSOLE_BG_BLUE`    |
| Magenta | `CONSOLE_FG_MAGENTA` | `CONSOLE_BG_MAGENTA` |
| Cyan    | `CONSOLE_FG_CYAN`    | `CONSOLE_BG_CYAN`    |
| White   | `CONSOLE_FG_WHITE`   | `CONSOLE_BG_WHITE`   |

For the **bright** versions of these colours, add `BRIGHT` after `FG` or `BG`.
For example: `CONSOLE_FG_BRIGHT_YELLOW`

To use these, use `console_set_color(color)`, replacing `color` with any of the above.
To reset the colour, use `console_reset_colour`.

Depending on the console mode, `console_set_foreground_rgb(r, g, b)` and `console_set_background_rgb(r, g, b)` may be available.
This library supports **Truecolor**, which you can [read more about](https://en.wikipedia.org/wiki/Color_depth#True_color_.2824-bit.29).

#### Cursor
You can move the cursor around by using the following:
- `console_reset_cursor`: Resets the cursor to (0,0)
- `console_move_cursor(line, column)`: Moves the cursor to the line and column

#### Screen clearing
You can clear the screen in two ways:
- `console_clear_screen`: Clears the whole screen
- `console_clear_line`: Clears the current line
  - You may wish to use `\r` after using this, to move the cursor to the beginning of the line

#### Graphics modes
| Graphics mode    | Mode                                | Reset sequence                            |
| :--------------- | :---------------------------------- | :---------------------------------------- |
| Reset            | `CONSOLE_GRAPHICS_RESET`            |                                           |
| Bold             | `CONSOLE_GRAPHICS_BOLD`             | `CONSOLE_GRAPHICS_RESET_BOLD`             |
| Dim/Faint        | `CONSOLE_GRAPHICS_DIM`              | `CONSOLE_GRAPHICS_RESET_DIM`              |
| Italic           | `CONSOLE_GRAPHICS_ITALIC`           | `CONSOLE_GRAPHICS_RESET_ITALIC`           |
| Underline        | `CONSOLE_GRAPHICS_UNDERLINE`        | `CONSOLE_GRAPHICS_RESET_UNDERLINE`        |
| Blinking         | `CONSOLE_GRAPHICS_BLINKING`         | `CONSOLE_GRAPHICS_RESET_BLINKING`         |
| Inverse/Reverse  | `CONSOLE_GRAPHICS_INVERSE_REVERSE`  | `CONSOLE_GRAPHICS_RESET_INVERSE_REVERSE`  |
| Hidden/Invisible | `CONSOLE_GRAPHICS_HIDDEN_INVISIBLE` | `CONSOLE_GRAPHICS_RESET_HIDDEN_INVISIBLE` |
| Stikethrough     | `CONSOLE_GRAPHICS_STRIKETHROUGH`    | `CONSOLE_GRAPHICS_RESET_STRIKETHROUGH`    |

To use these, use `console_graphics_set(mode)`, use `CONSOLE_GRAPHICS_RESET` to reset the graphics mode.

#### Screen modes
| Screen mode                | Definition                        |
| :------------------------- | :-------------------------------- |
| 40x25 Monochrome (2‑color) | `CONSOLE_MODE_40x25_MONOCHROME`   |
| 40x25 Color                | `CONSOLE_MODE_40x25_COLOR`        |
| 80x25 Monochrome (2‑color) | `CONSOLE_MODE_80x25_MONOCHROME`   |
| 80x25 Color                | `CONSOLE_MODE_80x25_COLOR`        |
| 320x200 4‑color            | `CONSOLE_MODE_320x200_4_COLOR`    |
| 320x200 Monochrome         | `CONSOLE_MODE_320x200_MONOCHROME` |
| 640x200 Monochrome         | `CONSOLE_MODE_640x200_MONOCHROME` |
| Line Wrapping              | `CONSOLE_MODE_LINE_WRAPPING`      |
| 320x200 Color              | `CONSOLE_MODE_320x200_COLOR`      |
| 640x200 16‑color           | `CONSOLE_MODE_640x200_16_COLOR`   |
| 640x350 Monochrome         | `CONSOLE_MODE_640x350_MONOCHROME` |
| 640x350 16‑color           | `CONSOLE_MODE_640x350_16_COLOR`   |
| 640x480 Monochrome         | `CONSOLE_MODE_640x480_MONOCHROME` |
| 640x480 16‑color           | `CONSOLE_MODE_640x480_16_COLOR`   |
| 320x200 256‑color          | `CONSOLE_MODE_320x200_256_COLOR`  |

To use these, use `console_mode_set(mode)`, and `console_mode_reset` to reset it to the default.

#### Common private modes
These are a few common private modes that this library supports, these are implemented in most terminals **but not all**.

| Mode                                       | Description                  |
| :----------------------------------------- | :--------------------------- |
| `console_private_cursor_invisible`         | Make the cursor invisible    |
| `console_private_cursor_visible`           | Make the cursor visible      |
| `console_private_screen_restore`           | Restore the screen           |
| `console_private_screen_save`              | Save the screen              |
| `console_private_alternate_buffer_enable`  | Enable the alternate buffer  |
| `console_private_alternate_buffer_disable` | Disable the alternate buffer |

### C++ version
The C++ version of this is very similar to the C version, the difference is that it's structured. Copy the `ansi_console.hpp` file to your project, and import it.

All of the library functionality for the C++ version is within the namespace `Console`, you may wish to
import by using `using namespace Console`.

#### Colours
This is an `enum`, with the values:

| Colour  | `enum` value     |
| :------ | :--------------- |
| Black   | `Color::Black`   |
| Red     | `Color::Red`     |
| Green   | `Color::Green`   |
| Yellow  | `Color::Yellow`  |
| Blue    | `Color::Blue`    |
| Magenta | `Color::Magenta` |
| White   | `Color::White`   |

And their bright values begin with `Bright_`, for example: `Color::Bright_Black`.

To use these, use `set_foreground_color(color)` and `set_background_color(color)`.
To reset the colour, use `reset_colour`.

Depending on the console mode, `set_foreground_rgb(r, g, b)` and `set_background_rgb(r, g, b)` may be available.
This library supports **Truecolor**, which you can [read more about](https://en.wikipedia.org/wiki/Color_depth#True_color_.2824-bit.29).

#### Cursor
You can move the cursor around by using the following:
- `reset_cursor`: Resets the cursor to (0,0)
- `move_cursor(line, column)`: Moves the cursor to the line and column

#### Screen clearing
You can clear the screen in two ways:
- `clear_screen`: Clears the whole screen
- `clear_line`: Clears the current line
  - You may wish to use `\r` after using this, to move the cursor to the beginning of the line

#### Graphics modes
| Graphics mode    | Mode                          |
| :--------------- | :---------------------------- |
| Reset            | `GraphicsMode::Reset`         |
| Bold             | `GraphicsMode::Bold`          |
| Dim/Faint        | `GraphicsMode::Dim`           |
| Italic           | `GraphicsMode::Italic`        |
| Underline        | `GraphicsMode::Underline`     |
| Blinking         | `GraphicsMode::Blinking`      |
| Inverse/Reverse  | `GraphicsMode::Reverse`       |
| Hidden/Invisible | `GraphicsMode::Invisible`     |
| Stikethrough     | `GraphicsMode::Strikethrough` |

To use these, use `graphics_set(mode)`, use `GraphicsMode::Reset` to reset the graphics mode.

#### Screen modes
| Screen mode                | Definition                        |
| :------------------------- | :-------------------------------- |
| 40x25 Monochrome (2‑color) | `ScreenMode::_40x25_MONOCHROME`   |
| 40x25 Color                | `ScreenMode::_40x25_COLOR`        |
| 80x25 Monochrome (2‑color) | `ScreenMode::_80x25_MONOCHROME`   |
| 80x25 Color                | `ScreenMode::_80x25_COLOR`        |
| 320x200 4‑color            | `ScreenMode::_320x200_4_COLOR`    |
| 320x200 Monochrome         | `ScreenMode::_320x200_MONOCHROME` |
| 640x200 Monochrome         | `ScreenMode::_640x200_MONOCHROME` |
| Line Wrapping              | `ScreenMode::_LINE_WRAPPING`      |
| 320x200 Color              | `ScreenMode::_320x200_COLOR`      |
| 640x200 16‑color           | `ScreenMode::_640x200_16_COLOR`   |
| 640x350 Monochrome         | `ScreenMode::_640x350_MONOCHROME` |
| 640x350 16‑color           | `ScreenMode::_640x350_16_COLOR`   |
| 640x480 Monochrome         | `ScreenMode::_640x480_MONOCHROME` |
| 640x480 16‑color           | `ScreenMode::_640x480_16_COLOR`   |
| 320x200 256‑color          | `ScreenMode::_320x200_256_COLOR`  |

To use these, use `mode_set(mode)`, and `console_mode_reset` to reset it to the default.

#### Common private modes
These are a few common private modes that this library supports, these are implemented in most terminals **but not all**.

These are all in another namespace, `Console::Private`, which you can also include via `using namespace Private`.

| Mode                                | Description                  |
| :---------------------------------- | :--------------------------- |
| `Private::cursor_invisible`         | Make the cursor invisible    |
| `Private::cursor_visible`           | Make the cursor visible      |
| `Private::screen_restore`           | Restore the screen           |
| `Private::screen_save`              | Save the screen              |
| `Private::alternate_buffer_enable`  | Enable the alternate buffer  |
| `Private::alternate_buffer_disable` | Disable the alternate buffer |