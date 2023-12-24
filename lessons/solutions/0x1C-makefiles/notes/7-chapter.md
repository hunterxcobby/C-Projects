**Variables in Makefiles:**

In Makefiles, variables are used to store values that can be reused throughout the file. They make it easy to manage and modify project configurations. Here's how you define and use variables:

**Setting Variables:**
```make
CC = gcc
CFLAGS = -Wall -O2
```

In this example:
- `CC` is a variable storing the compiler command (`gcc`).
- `CFLAGS` is a variable storing compiler flags (`-Wall -O2`).

**Using Variables:**
```make
my_program: main.c functions.c
    $(CC) $(CFLAGS) $^ -o $@
```

In this example:
- `$(CC)` expands to `gcc`.
- `$(CFLAGS)` expands to `-Wall -O2`.
- `$^` expands to `main.c functions.c`.
- `$@` expands to `my_program`.

**Overriding Variables:**
You can override variable values by redefining them:
```make
CC = clang
```
Now, `$(CC)` will expand to `clang` instead of `gcc`.

**Automatic Variables:**
```make
my_program: main.o functions.o
    $(CC) $(CFLAGS) $^ -o $@
```
Here, `$^` expands to `main.o functions.o`, saving you from listing dependencies manually.

**Conditional Assignment:**
```make
DEBUG ?= 0
```
This sets `DEBUG` to `0` if it's not already defined.

**Command Substitution:**
```make
TODAY := $(shell date)
```
This captures the output of the `date` command in the variable `TODAY`.

**Using Environment Variables:**
```make
USER := $(USER)
```
This sets `USER` to the value of the `USER` environment variable.

**Multi-line Variables:**
```make
SOURCES = \
    file1.c \
    file2.c
```
This defines a multi-line variable `SOURCES`.

Variables enhance the flexibility and maintainability of Makefiles, allowing you to change settings in one place and affect multiple rules.