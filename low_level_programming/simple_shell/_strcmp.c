#include <stdio.h>
#include <string.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */

int _strcmp(const char *string1, const char *string2);

int main(void)
{
    char s1[] = "Hello";
    char s2[] = "World!";

    printf("%d\n", _strcmp(s1, s2));
    printf("%d\n", _strcmp(s2, s1));
    printf("%d\n", _strcmp(s1, s1));
    return (0);
}

int _strcmp(const char *string1, const char *string2)
{
    int i = 0;
    
    while (string1[i] != '\0')
    {
        if (string1[i] != string2[i])
        {
            return string1[i] -  string2[i];
        }
        i = i + 1;
    }
    
    while (string2[i] != '\0')
    {
        if (string2[i] != string1[i])
        {
            return string2[i] -  string2[i];
        }
        i = i + 1;
    }
    
    return string1[i] -  string2[i];
}
