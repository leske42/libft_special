*This project has been created as part of the 42 curriculum by mhuszar.*

## Description
Libft is a personal C utility library that reimplements a set of standard C library and helper functions. The goal is to deepen understanding of low-level programming & memory management by building a reliable, reusable foundation for later projects.

This version is written in x86-64 inline assembly! Don't try this at `~`.

The Makefile creates a standalone static library (`libft.a`) with functions for strings, memory, character checks, number conversion, output helpers, and linked list utilities.

## Instructions
### Build
From the libft folder:

```sh
make
```

This builds `libft.a`.

### Use in another program
Compile your program and link against the library:

```sh
cc -Wall -Wextra -Werror -I. your_file.c -L. -lft
```

Flag explanation:
- `-I/path/to/libft` adds a directory (in this case the current dir `.`) to the header search path (this is technically not needed if the header is in current dir, but nice to add).
- `-L.` similarly, adds the current directory to the library search path.
- `-lft` links against `libft.a` (or `libft.so` if present).

Or you can do:
```sh
cc -Wall -Wextra -Werror your_file.c libft.a
```

## Library Contents (Detailed)
### Pointer arguments and undefined behavior
Unless otherwise specified, functions that take pointer arguments expect non-NULL, valid pointers. Passing `NULL`, invalid addresses, or insufficient buffers results in undefined behavior. Examples include most string/memory utilities.

### String and memory utilities
- `ft_strlen` - length of a string.
- `ft_strlcpy`, `ft_strlcat` - size-aware string copy/concat.
- `ft_strncmp`, `ft_strchr`, `ft_strrchr`, `ft_strnstr` - string comparisons and searches.
- `ft_strdup` - duplicate a string.
- `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` - memory operations.
- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split` - string creation and transformation helpers.
- `ft_strmapi`, `ft_striteri` - apply a function over a string.

### Character checks and conversions
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` - character classification.
- `ft_tolower`, `ft_toupper` - case conversion.
- `ft_atoi`, `ft_itoa` - integer/string conversion.

### Output helpers
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` - write data to a file descriptor.

### Linked list utilities
- `ft_lstnew` - create a new list node.
- `ft_lstadd_front`, `ft_lstadd_back` - add nodes to front/back.
- `ft_lstsize` - count nodes.
- `ft_lstlast` - get the last node.
- `ft_lstdelone`, `ft_lstclear` - delete nodes and clear a list.
- `ft_lstiter` - iterate and apply a function.
- `ft_lstmap` - map a function over a list to create a new list.

## Resources
- RTFM!! https://man7.org/linux/man-pages/man3/intro.3.html
- And the Libft subject PDF
- Rules to avoid common inline ASM mistakes: https://nullprogram.com/blog/2024/12/20/
    - After many months of working on this project, I found myself 100% agreeing with this list, super recommended read

### AI usage
AI was used to clarify errors during development (e.g., debugging shitty clobber lists and memory management pitfalls) and to generate most of this README. All functions were implemented manually.
