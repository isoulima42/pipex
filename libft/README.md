*This project has been created as part of the 42 curriculum by isoulima.*

# Libft

<img src="score.png" width="150" alt="Score 125/100">

![Language](https://img.shields.io/badge/Language-C-blue)
![Norminette](https://img.shields.io/badge/Norminette-OK-brightgreen)

## Description

Libft is the very first project of the 42 curriculum. It consists of re-implementing a library of standard C functions, then extending it with additional utility functions. The project gives an in-depth understanding of how libc functions work, of dynamic memory management and of string manipulation. The bonus part introduces linked lists.

---

## Instructions

### Compilation

```bash
make        # builds the libft.a library
make bonus  # builds with the bonus functions (linked lists)
make clean  # removes the .o files
make fclean # removes the .o files and libft.a
make re     # rebuilds everything
```

### Usage

Include the header and compile with the library:

```bash
cc main.c libft.a
```

```c
#include "libft.h"

int main(void)
{
    char *s = ft_strdup("Hello 42");
    ft_putstr_fd(s, 1);
    free(s);
    return (0);
}
```

---

## Features

### Libc functions

| Function | Description |
|----------|-------------|
| `ft_isalpha` | checks for a letter |
| `ft_isdigit` | checks for a digit |
| `ft_isalnum` | checks for an alphanumeric character |
| `ft_isascii` | checks for an ASCII character |
| `ft_isprint` | checks for a printable character |
| `ft_strlen` | length of a string |
| `ft_memset` | fills a memory area |
| `ft_bzero` | zeroes a memory area |
| `ft_memcpy` | copies a memory area |
| `ft_memmove` | copies with overlap handling |
| `ft_strlcpy` | size-bounded string copy |
| `ft_strlcat` | size-bounded string concatenation |
| `ft_toupper` | converts to uppercase |
| `ft_tolower` | converts to lowercase |
| `ft_strchr` | finds a character in a string |
| `ft_strrchr` | finds a character starting from the end |
| `ft_strncmp` | compares two strings over n characters |
| `ft_memchr` | finds a byte in a memory area |
| `ft_memcmp` | compares two memory areas |
| `ft_strnstr` | finds a substring |
| `ft_atoi` | converts a string to an integer |
| `ft_calloc` | zero-initialized memory allocation |
| `ft_strdup` | duplicates a string |

### Additional functions

| Function | Description |
|----------|-------------|
| `ft_substr` | extracts a substring |
| `ft_strjoin` | concatenates two strings |
| `ft_strtrim` | removes characters from the start/end |
| `ft_split` | splits a string on a delimiter |
| `ft_itoa` | converts an integer to a string |
| `ft_strmapi` | applies a function to each character (new string) |
| `ft_striteri` | applies a function to each character (in place) |
| `ft_putchar_fd` | writes a character to an fd |
| `ft_putstr_fd` | writes a string to an fd |
| `ft_putendl_fd` | writes a string + newline to an fd |
| `ft_putnbr_fd` | writes a number to an fd |

### Bonus (linked lists)

| Function | Description |
|----------|-------------|
| `ft_lstnew` | creates a new element |
| `ft_lstadd_front` | adds at the front |
| `ft_lstsize` | counts the elements |
| `ft_lstlast` | returns the last element |
| `ft_lstadd_back` | adds at the back |
| `ft_lstdelone` | deletes one element |
| `ft_lstclear` | deletes all elements |
| `ft_lstiter` | applies a function to each element |
| `ft_lstmap` | applies a function and creates a new list |

---

## Technical choices

- Static library (`libft.a`) built with `ar -rc`
- Strict compilation flags: `-Wall -Wextra -Werror`
- No global variables
- Rigorous memory management with `malloc` / `free`
- Single header `libft.h` included through the compiler's `-include` flag
- The bonus functions are compiled separately with `make bonus`

---

## Resources

- `man 3` pages of the matching libc functions
- Documentation on linked lists in C
- Official 42 subject

---

## AI usage

AI was used only to:
- clarify some points of the subject
- structure this README

The implementation, the logic and the understanding of the code were done manually.

---

## Author

42 Lausanne
Login: isoulima
