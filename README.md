_This project has been created as part of the 42 curriculum by kugurlu._

## Description
The **ft_printf** project is a custom implementation of the standard C library `printf` function. The goal is to recreate a versatile formatting tool that handles various data types and mimics the behavior of the original `printf`. This project serves as an introduction to **variadic functions** in C, requiring a deep understanding of how to manage an unknown number of arguments using the `stdarg.h` library.

## Instructions

### Compilation
The project includes a `Makefile` that compiles the source files with the required `-Wall -Wextra -Werror` flags. To compile the library, run:

```bash
make
```

This will generate the libftprintf.a library at the root of the repository.

### Usage

To use ft_printf in your own C projects, include the header and link the compiled library:

1. Include the header in your code: #include "ft_printf.h".

2. Compile your program with the library:
	```bash
	cc <your_file.c> libftprintf.a -o <save_file_name>
	```

### Cleanup

- To remove object files: `make clean`.

- To remove object files and the library: `make fclean`.

- To recompile everything: `make re`.

## Algorithm and Data Structure Justification

The project utilizes a Modular Dispatcher algorithm combined with a State-Tracking Structure (`t_flags`).

1. Data Structure (`t_flags`): A structure is used to store the state of various flags (`-`, `0`, `.`, `#`, `+`, `space`), width, and precision. This approach is more efficient than passing multiple parameters and allows for easy extensibility.

2. Parsing: The format string is parsed character by character. When a `%` is encountered, the `flag_checker` populates the structure.

3. Execution: Based on the conversion type (e.g., `d`, `s`, `x`), the engine dispatches the request to specific "writer" functions (`numeric_writers`, `alphabetic_writers`, `hexadecimal_writers`).

4. Formatting Logic: The algorithm calculates "padding" (spaces) and "precision" (zeros) before printing the actual value to ensure the output matches the exact width and alignment requirements of the original `printf`.

## Resources
- 42 Subjects: The official ft_printf subject PDF.

- Documentation: man 3 printf and stdarg.h documentation.

- Tutorials: Various guides on variadic functions and C memory management.

### AI Usage Disclosure

Artificial Intelligence was utilized during this project for the following tasks:

- Logic Debugging: AI was used to identify edge cases in the interaction between the '0' flag and precision settings in numeric conversions.

- Test Case Generation: AI helped generate specific test strings (like `"%5%"`) to verify that the percentage sign correctly respects width and alignment flags.

- Documentation: AI assisted in drafting the technical justification for the chosen data structures in this README.
