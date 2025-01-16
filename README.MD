# 📚 Libft - Custom C Library

## 🚀 About the Project
**Libft** is a personal library developed as part of the 42 curriculum. It includes fundamental C functions recreated from scratch, along with additional utility functions, to serve as a toolbox for future projects.  
This repository also includes **ft_printf**, a custom implementation of the C `printf` function.

---

## 🛠 Features
### 📂 **Libft**
1. **Libc Functions**: Reimplementations of standard C library functions like `ft_strlen`, `ft_memcpy`, and `ft_atoi`.
2. **Additional Functions**: Utility functions like `ft_split`, `ft_strjoin`, and `ft_itoa` for enhanced functionality.
3. **Linked List Management**: Functions to handle linked lists, such as `ft_lstnew`, `ft_lstadd_back`, and `ft_lstmap`.

### ✨ **ft_printf**
1. Supports standard conversions:
   - `%c` (character), `%s` (string), `%p` (pointer), `%d`/`%i` (integer), `%u` (unsigned), `%x`/`%X` (hexadecimal), `%%` (percent).
2. Implements variadic functions for handling dynamic arguments.

---
## 📘 Usage

### 🛠 How to Use the Library
1. **Clone the Repository**:
	```sh
	git clone https://github.com/yourusername/libft.git
	cd libft
	```

2. **Compile the Library**:
	```sh
	make
	```
	This will generate the `libft.a` file, which is the static library containing all the compiled functions.

### 📂 Using `libft.a` in Other Projects

#### With a Makefile
	- Ensure `libft.a` is in your project directory or specify the path to it.
	- Add the following lines to your `Makefile`:
	  ```makefile
	  LIBFT_DIR = /path/to/libft
	  LIBFT = $(LIBFT_DIR)/libft.a
	  LIBFT_INC = -I$(LIBFT_DIR)

	  all: $(NAME)

	  $(NAME): $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

	  %.o: %.c
			$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@
	  ```