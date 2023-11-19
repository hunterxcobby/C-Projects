#include <stdio.h>
#include <string.h>

/**
 * This code is to illustrate the linear search 
 * in a sorting algorithms 
 * in this example we use linear search to find if
 * a name exists in an array of strings
 * if it is we print found and if not found we print 
 * not found 
 * IN higher bounds, This has a O(n) since it takes a number of time to
 * to find our item
 * IN lower bounds It has omega(1) because if we are lucky enough and
 * 0 is the first item in the array, it saves a lot of time
 * I am sorry if i do not find the right way to explain this but i will
 * later create nodes on it in the notes direc
*/
int main(void)
{
    int i;
    char *names[] = {
        "Cobby",
        "Kelvin",
        "Bob",
        "Billy",
        "Akwesi",
        "Kelvin",
        "Santan"
    };

    for(i = 0; i < 7; i ++)
    {
        if(strcmp(names[i], "Billy") == 0)
        {
            printf("Found\n");
            return (0);
        }
    }
    printf("Not Found\n");
    return (1);
}