*This activity has been created as part of the 42 curriculum by csodini.*

# ft_printf

## Description

`ft_printf` is a 42 project whose goal is to recreate a simplified version of the standard C `printf` function.

The function prototype is:

```c
int	ft_printf(const char *format, ...);
```

The project introduces variadic functions in C through the use of `stdarg.h`, especially:

- `va_list`
- `va_start`
- `va_arg`
- `va_end`

The implemented function parses a format string, detects conversion specifiers introduced by `%`, retrieves the corresponding variadic argument, prints it to standard output, and returns the number of characters printed.

The supported conversions are:

| Conversion | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints an unsigned integer in lowercase hexadecimal |
| `%X` | Prints an unsigned integer in uppercase hexadecimal |
| `%%` | Prints a percent sign |

## Instructions

### Compilation

To compile the library:

```bash
make
```

This creates the static library:

```text
libftprintf.a
```

### Clean object files

```bash
make clean
```

### Clean object files and library

```bash
make fclean
```

### Rebuild the project

```bash
make re
```

### Example usage

Create a temporary `main.c` file:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello %s, number: %d\n", "world", 42);
	return (0);
}
```

Compile it with:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a
```

Then run:

```bash
./a.out
```

Expected output:

```text
Hello world, number: 42
```

## Algorithm and data structure

The implementation is based on a linear parsing of the format string.

The main function `ft_printf` iterates through each character of the input format. If the current character is not `%`, it is printed directly using a helper function that returns the number of written characters.

When a `%` is found, the next character is interpreted as a conversion specifier. A dispatcher function selects the correct printing function depending on the specifier.

For example:

- `%c` retrieves an `int` with `va_arg`, casts it to `char`, and prints it.
- `%s` retrieves a `char *` and prints the string.
- `%d` and `%i` retrieve an `int` and print it in base 10.
- `%u` retrieves an `unsigned int` and prints it in base 10.
- `%x` and `%X` retrieve an `unsigned int` and print it in base 16.
- `%p` retrieves a `void *` and prints the address in hexadecimal format.
- `%%` prints a literal percent sign without consuming any variadic argument.

No complex data structure is required. The project mainly relies on:

- a `va_list` to iterate through variadic arguments;
- helper functions returning character counts;
- recursive number-printing functions for decimal and hexadecimal output.

The recursive approach is used for number conversion because it allows digits to be printed in the correct order without allocating an intermediate buffer.

## Project structure

```text
.
├── Makefile
├── README.md
├── ft_printf.h
├── ft_printf.c
├── ft_putchar_count.c
├── ft_putstr_count.c
├── ft_putnbr_count.c
├── ft_putuint_count.c
├── ft_puthex_count.c
└── ft_putptr_count.c
```

## Resources

Useful references:

- `man 3 printf`
- `man 3 stdarg`
- `man 2 write`
- C documentation about variadic functions
- 42 Norm documentation
- Peer discussions and testing against the original `printf`

## AI usage

AI was used as a learning and explanation tool during the project.

It helped with:

- understanding variadic functions and the role of `stdarg.h`;
- clarifying the behavior of `va_list`, `va_start`, `va_arg`, and `va_end`;
- structuring the project into small helper functions;
- reviewing the Makefile logic and README structure.

AI was not used to replace the learning process. The implementation choices, testing, debugging, and final code understanding remain the responsibility of the student.