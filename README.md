_This project has been created as part of the 42 curriculum by kugurlu._

## Description

The **ft_printf** project consists of a reproduction of the standard C library's `printf` function. The purpose is to create a versatile and flexible formatting tool for formatting/printing the many different types of variable input that exist in C, which closely resembles the original usage of `printf`. This project will introduce you to **variadic functions** in C and how to handle an unknown number of arguments using the stdarg.h library.

## Instructions

### Compilation

- The project includes a `Makefile` that compiles the source files with the required `-Wall -Wextra -Werror` flags. To compile the library, run:

	```bash
	make
	```

- To get bonus features you need to run:

	```bash
	make bonus
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

A Modular Dispatcher algorithm and a new mechanism called the State-Tracking Structure (`t_flags`), have been developed as part of a project to optimize the performance of the printf API.

- Data Structure (`t_flags`): Using a t_flags structure is more efficient than passing multiple parameters related to the state of flags (`-`, `0`, `.`, `#`, `+` and `space`), together with width and precision. Also, this structure provides ease of extensibility.

- Parsing: The algorithm parses through each character of a `format` string; when a `%` character is found, the `flag_checker` builds the t_flags structure with flag-related information.

- Dispatching: When dispatching the formatted output to the appropriate writer functions ( `numeric_writers`, `alphabetic_writers`, and `hexadecimal_writers`) based on the conversion type specified ( e.g. `d`, `s`, and `x` ), the printf engine performs the appropriate writer function.

- Formatting Logic: Padding (spaces) and precision (0) are calculated before printing the final value in order to ensure that the width and alignment of the output are consistent with the input data.

## Resources

- 42 Subjects: The official ft_printf subject PDF.

- Documentation: man 3 printf and stdarg.h documentation.

- Tutorials: Various guides on variadic functions and C memory management.

### AI Usage Disclosure

Artificial Intelligence was utilized during this project for the following tasks:

- Logic Debugging: AI was used to identify edge cases in the interaction between the '0' flag and precision settings in numeric conversions.

- Test Case Generation: AI helped generate specific test strings (like `"%5%"`) to verify that the percentage sign correctly respects width and alignment flags.

- Documentation: AI assisted in drafting the technical justification for the chosen data structures in this README.
