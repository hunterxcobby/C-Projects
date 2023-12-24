The most common and useful rules in Makefiles depend on the nature of your project and programming language. However, there are some general-purpose rules and variables that are commonly used. Here are a few:

1. **Variables:**
   - **CC (Compiler):**
     ```make
     CC = gcc
     ```
   - **CFLAGS (Compiler Flags):**
     ```make
     CFLAGS = -Wall -O2
     ```
   - **LDLIBS (Library Flags):**
     ```make
     LDLIBS = -lm
     ```

2. **Implicit Rule for Compiling C Source Files:**
   ```make
   %.o: %.c
       $(CC) $(CFLAGS) -c $<
   ```

3. **Implicit Rule for Linking Object Files:**
   ```make
   %: %.o
       $(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
   ```

4. **Phony Targets (Targets that are not filenames):**
   ```make
   .PHONY: clean all
   clean:
       rm -f *.o my_program

   all: my_program
   ```

5. **Wildcard Function (Matches files using wildcards):**
   ```make
   SOURCES = $(wildcard *.c)
   OBJECTS = $(SOURCES:.c=.o)
   ```

6. **VPATH (Search Path for Prerequisites):**
   ```make
   VPATH = src include
   ```

7. **Pattern Rules (Rules that can match multiple targets):**
   ```make
   %.o: %.c
       $(CC) $(CFLAGS) -c $< -o $@
   ```

8. **Automatic Variables:**
   - `$@`: The target.
   - `$^`: All prerequisites.
   - `$<`: The first prerequisite.

These rules and variables provide a foundation for building Makefiles. Depending on your project, you may need to customize them or add more specific rules. If you have a particular type of project or language in mind, I can provide more targeted examples!