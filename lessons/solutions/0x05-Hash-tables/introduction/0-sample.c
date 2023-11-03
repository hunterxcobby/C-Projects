#include <stdio.h>

#define CAPACITY 50000 /* Size of the HashTable.*/

unsigned long hash_function(char* str)
{
    int j;
    unsigned long i = 0;

    for (j = 0; str[j]; j++)
    {
        i = i + str[j];
        printf("%ld => ", i);
        printf("Ascii value for %c is %d\n ", str[j], str[j]);
    }
    return i % CAPACITY;
}

int main(void)
{
    hash_function("Cobby");

    return(0);
}