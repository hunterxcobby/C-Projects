### Step 1: Create a Project Directory

Start by creating a directory for your project. For example:

```bash
mkdir my_project
cd my_project
```

### Step 2: Create Source Files

Create some source files in the project directory. For example, let's create two C files: `main.c` and `helper.c`.

**main.c:**
```c
#include <stdio.h>
#include "helper.h"

int main() {
    greet();
    return 0;
}
```

**helper.c:**
```c
#include <stdio.h>

void greet() {
    printf("Hello from the helper!\n");
}
```

**helper.h:**
```c
#ifndef HELPER_H
#define HELPER_H

void greet();

#endif
```

### Step 3: Create a Makefile

Now, create a Makefile in the project directory. Open a text editor and create a file named `Makefile` with the following content:

```make
CC = gcc
CFLAGS = -Wall

all: my_program

my_program: main.o helper.o
	$(CC) $(CFLAGS) -o my_program main.o helper.o

main.o: main.c helper.h
	$(CC) $(CFLAGS) -c main.c

helper.o: helper.c helper.h
	$(CC) $(CFLAGS) -c helper.c

clean:
	rm -f my_program *.o
```

### Step 4: Explain the Makefile

- **CC:** Compiler used (gcc).
- **CFLAGS:** Compiler flags (Wall for warnings).
- **all:** Default target. It depends on `my_program`.
- **my_program:** Target executable. Depends on `main.o` and `helper.o`.
- **main.o, helper.o:** Object files. Rules specify how to create them from corresponding source files.
- **clean:** Rule to remove generated files.

### Step 5: Build the Project

Open a terminal in the project directory and run:

```bash
make
```

This will compile the source files and generate the executable `my_program`.

### Step 6: Run the Program

After successful compilation, run the program:

```bash
./my_program
```

You should see the output "Hello from the helper!"

### Step 7: Clean the Project

To clean up the generated files, run:

```bash
make clean
```

This removes the executable and object files.

### Step 8: Experiment

You can modify the source files and rerun `make` to see how Makefile efficiently recompiles only the necessary parts.

Congratulations! You've successfully created and used a Makefile for a simple C project.