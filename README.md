*This project has been created as part of the 42 curriculum by rzbib.*

# ft_printf

## Description
The ft_printf project consists of recreating the behavior of the standard C library function printf().
The goal is to understand variadic functions in C and learn how formatted output works.
The project produces a static library named libftprintf.a, containing a custom implementation of ft_printf().

The function supports the following conversions:
- %c : Prints a single character.
- %s : Prints a string.
- %p : Prints a pointer address in hexadecimal format.
- %d : Prints a signed decimal integer.
- %i : Prints an integer in decimal format.
- %u : Prints an unsigned decimal integer.
- %x : Prints a hexadecimal number using lowercase letters.
- %X : Prints a hexadecimal number using uppercase letters.
- %% : Prints a percent sign.

## Instructions
### Compilation
To compile the library, run:
```bash
make
```

This generates:
```text
libftprintf.a
```

Available Makefile rules:
- `make clean`: Remove object files.
- `make fclean`: Remove object files and `libft.a`.
- `make re`: Rebuild the library.

### Usage
Include the header file in your C program:

```c
#include "ft_printf.h"
```

Compile your program with the static library:

```bash
cc main.c -L. -lftprintf -I. -o program
```

Example:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "World");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Character: %c\n", 'A');
    ft_printf("Pointer: %p\n", (void *)main);
    ft_printf("Percentage: %%\n");
    return (0);
}
```

## Algorithm and Data Structures
### Algorithm

The implementation uses a character-by-character parsing algorithm.

The function reads the format string from beginning to end using an integer index.

When a normal character is encountered, it is printed directly using write().

When a percent sign (%) is encountered, the function checks the next character to identify the conversion specifier.

The corresponding argument is retrieved using va_arg() and passed to the appropriate printing function.

Each printing function returns the number of characters successfully written. These values are accumulated to calculate the final return value of ft_printf().

### Number Conversion Algorithm

For decimal and hexadecimal numbers, the project uses a recursive base-conversion algorithm.

The algorithm divides the number by the requested base and prints the remainder as a digit.

For example, converting 42 to hexadecimal:

- 42 / 16 = 2, remainder 10.
- 2 / 16 = 0, remainder 2.
- The remainders are printed in reverse order.
- The result is 2a.

The same function supports decimal and hexadecimal conversions by changing the base and digit characters.

### Data Structures

The project uses the following C language features:

- **va_list**: Stores and accesses the variable arguments passed to ft_printf().
- **unsigned long**: Allows number conversion without signed integer limitations.
- **uintptr_t**: Allows a pointer to be represented as an unsigned integer for hexadecimal printing.
- **Integer counters**: Track the number of characters printed.

No complex data structures or dynamic memory allocation are required.

### Technical Choices
- write() is used instead of printf() to display characters.
- va_start(), va_arg(), and va_end() manage variadic arguments.
- Recursive division is used for number conversion.
- Separate utility functions keep the implementation modular and reusable.
- A long variable is used when handling negative integers to safely process INT_MIN.

### Resources

The following resources were used to understand the project and its implementation:

- 42 ft_printf subject.
- Linux manual pages:
    - man printf
    - man write
    - man stdarg
    - man va_start
    - man va_arg
- C programming documentation: https://en.cppreference.com/w/c
- GNU C Library documentation: https://www.gnu.org/software/libc/manual/

- libftTester by Tripouille: https://github.com/Tripouille/libftTester
  - Used to test the behavior of the implemented functions.

- Used the following articles as learning resources:
    - geeksforgeeks: 
        - https://www.geeksforgeeks.org/c/variadic-functions-in-c/
        - https://www.geeksforgeeks.org/c/how-to-write-your-own-printf-in-c/
    - linkedin: 
        - https://www.linkedin.com/pulse/recreate-printf-c-paul-stuart-hun0c


# AI Usage

AI was used as a learning and assistance tool during this project.

It was used for:

- Reviewing the original implementation and identifying potential errors.
- Correcting the Makefile and project structure.
- Explaining edge cases such as INT_MIN and null strings.
- Preparing the README documentation.

The purpose of using AI was to support understanding, debugging, and code review. The implementation should be reviewed and tested by the student to ensure a full understanding of every function.

## Author
RAZAN ZBIB | 
42 Login: rzbib | 
GitHub: razan-z