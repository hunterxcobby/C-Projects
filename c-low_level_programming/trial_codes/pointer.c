#include <stdio.h>

int main(void)
{
int x = 10;
int *ptr = &x;   // ptr points to the memory address of x

int value = *ptr;  // Dereferencing ptr to access the value stored at that memory address

printf(" The memory address is %p\n", ptr);
printf(" The value of the dereferenced pointer is %d\n", value);

return (0);
}
