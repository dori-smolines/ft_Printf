# ft_printf

*This project has been created as part of the 42 curriculum by smolines.*

## Description

**ft_printf** is a custom C library that recreates the behavior of the standard `printf()` function. The goal isn't just to reproduce its output, but to understand how a function can accept a **variable number of arguments** and dispatch its behavior based on a format string parsed at runtime.

```c
int ft_printf(const char *format, ...);
```

Given a format string containing conversion specifiers (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`), `ft_printf()` writes the corresponding formatted output to standard output and returns the number of characters printed, exactly like the original `printf()`.

This is a solo project, with no bonus features implemented (no flags, no field width/precision handling — only the required conversions).

## Algorithm explanation and justification

The implementation is built around three stages, executed as the format string is scanned character by character:

1. **Format string parsing.** `ft_printf()` iterates through the format string one character at a time. Every character that isn't a `%` is written directly to the output. When a `%` is encountered, the next character is treated as a conversion specifier.

2. **Variadic argument extraction.** Since the number and types of arguments aren't known at compile time, the function relies on the `<stdarg.h>` macros:
   - `va_start` initializes a `va_list` pointing to the first variadic argument, right after the format string.
   - `va_arg(args, type)` retrieves the next argument, advancing the internal cursor and interpreting the raw bytes according to the given `type` (e.g., `int`, `char *`, `void *`, `unsigned int`).
   - `va_end` cleans up the `va_list` once all arguments have been consumed.

   This was the core concept this project is meant to teach: since C has no built-in reflection, `va_arg` is the only mechanism available to safely read arguments whose type varies from one call to the next, and it must be told the expected type explicitly at each step — get the type wrong, and the behavior is undefined.

3. **Dispatch to a dedicated conversion handler.** Rather than a single large `if/else` chain handling every specifier's logic inline, each conversion (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`) is handled by its own small function. The main loop simply reads the specifier character and calls the matching handler, passing it the `va_list`. This design was chosen because:
   - It mirrors the structure of the subject's requirement for "well-structured and extensible code" — adding a new conversion later only means writing one new function and one new dispatch entry, without touching the parsing logic.
   - It keeps each conversion's formatting rules (e.g., hexadecimal digit mapping for `%x`/`%X`, `0x` prefixing and NULL-handling for `%p`) isolated and easy to test independently.

Since the buffer management of the original `printf()` wasn't required by the subject, each character is written directly via `write()` as it's produced, rather than being accumulated into an internal buffer before a single flush.

## Instructions

### Compilation

```bash
git clone <repo-url>
cd ft_printf
make
```

This produces `libftprintf.a` at the root of the repository.

Other available Makefile rules:

| Rule | Description |
|---|---|
| `make` / `make all` | Compiles the library |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and the library |
| `make re` | Recompiles everything from scratch |

### Using the library in another project

```c
#include "ft_printf.h"
```

Then link against the archive when compiling:

```bash
cc your_program.c -L. -lftprintf -o your_program
```

### Usage example

```c
#include "ft_printf.h"

int main(void)
{
    int written;

    written = ft_printf("Hello %s, you are %d years old (%p)\n", "world", 42, (void *)&written);
    ft_printf("Characters written: %d\n", written);
    return (0);
}
```

## Resources

- [Linux man-pages — `printf(3)`](https://man7.org/linux/man-pages/man3/printf.3.html) — reference for the exact expected output of each conversion
- [Linux man-pages — `stdarg(3)`](https://man7.org/linux/man-pages/man3/stdarg.3.html) — reference for `va_start`, `va_arg`, `va_copy`, and `va_end`
- [C99 standard, §7.15 (Variable arguments)](https://www.iso-9899.info/n1256.html) — the formal specification behind variadic functions in C

**AI usage disclosure:** AI (Claude, Anthropic) was used solely to help draft and structure this `README.md` file, including the algorithm explanation section. No AI assistance was used to design, write, or debug the C source code (format parsing, variadic argument handling, or the conversion functions), which was implemented independently in accordance with 42's academic policy on AI use.
