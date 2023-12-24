In a Makefile, rules define how to create a target (usually a file) from a set of prerequisites (other files or targets). Rules have the following structure:

```make
target: prerequisites
    recipe
```

- **Target:** The file or target that needs to be built.
- **Prerequisites:** The files or targets that are required for building the target.
- **Recipe:** The set of commands to build the target from the prerequisites.

Here's an example to illustrate how rules work:

```make
# Rule to build executable "my_program" from object files "main.o" and "helper.o"
my_program: main.o helper.o
    gcc -o my_program main.o helper.o

# Rule to build object file "main.o" from source file "main.c"
main.o: main.c helper.h
    gcc -c main.c

# Rule to build object file "helper.o" from source file "helper.c"
helper.o: helper.c helper.h
    gcc -c helper.c
```

In this example:

- The target `my_program` depends on the prerequisites `main.o` and `helper.o`. The recipe specifies how to link these object files into the executable.
- The target `main.o` depends on the source file `main.c` and the header file `helper.h`. The recipe specifies how to compile `main.c` into the object file.
- The target `helper.o` depends on the source file `helper.c` and the header file `helper.h`. The recipe specifies how to compile `helper.c` into the object file.

When you run `make`, it reads the Makefile, determines the dependencies, and executes the necessary recipes to build the specified target.

To use rules effectively:

1. **Define Dependencies Correctly:** Ensure that targets correctly depend on the prerequisites they need.
2. **Use Variables:** Define variables for compiler and flags to make the Makefile more flexible.
3. **Write Generic Rules:** Use pattern rules to avoid duplicating similar rules for different files.
