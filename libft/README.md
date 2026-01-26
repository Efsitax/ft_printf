_This project has been created as part of the 42 curriculum by kugurlu._

# Libft

## Description

This project implements `libc` library and simple linked list functions. This library has 43 functions. It helps to understand fundamentals of programing with C.

### Library Description

The library `libft.a` contains 43 functions that handle various tasks. The functions are categorized as follows:

- **Libc Functions:** Standard C functions (e.g., `ft_strlen`, `ft_memset`, `ft_atoi`).
- **Additional Functions:** Utility functions for string and memory manipulation (e.g., `ft_substr`, `ft_strjoin`).
- **Linked List Functions:** Functions to manipulate linked lists (e.g., `ft_lstnew`, `ft_lstadd_back`).

## Instructions

### Installation
1. Clone the repository.

	```bash
	git clone git@vogsphere.42istanbul.com.tr:vogsphere/intra-uuid-bc7aaec1-19d9-437d-9cca-687d3afc674e-7182931-kugurlu <folder-name>
	cd <folder-name>
	```

2. Compile the library.
	```bash
	make
	```
	This will generate `libft.a` on your folder.

3. Using the library.
	```bash
	cc -Wall -Wextra -Werror <your-c-file-name>.c libft.a
	```

### Make instructions
- Compiling the library.
	```bash
	make
	```

- Cleaning files that created during compilation.
	```bash
	make clean
	```

- Cleaning all files including `libft.a`.
	```bash
	make fclean
	```

- Recompiling the library.
	```bash
	make re
	```

## Resources

- 42 Libft Subject PDF file.
- `man` program for getting reference information.
- I used AI for geting know the way to solve the problem.
- I got help from my friends.
