#include <stdio.h>

int avg(int *num1, int num2, int num3)
{
    *num1 = 10;
    // int *p = &num1;
    
    // printf("the value of num1 is %d \n\n", *p);
    
    int avg_num;
    avg_num = ((*num1 + num2 + num3) / 3 );
    
    // adresses
     printf("These are the addresses of the declared function. \n");
     printf("the address of num1 is %p \n", &num1);
     printf("the address of num1 is %p \n", &num2);
     printf("the address of num1 is %p \n\n", &num3);
    
    // values 
     printf("These are the values of declared function. \n");
     printf("the current value of num1 is %d \n", *num1);
     printf("the value of num1 is %d \n", *num1);
     printf("the value of num2 is %d \n", num2);
     printf("the value of num3 is %d \n\n", num3);
    

    
    return avg_num;
} 

int main() {
    // Write C code here
    
    int a = 6;
    int b = 2;
    int c = 5;
    
    int average = avg(&a, b, c);

    // adresses
    
     printf("These are the addresses of main function. \n");
     printf("the address of a is %p \n", &a);
     printf("the address of b is %p \n", &b);
     printf("the address of c is %p \n\n", &c);

    
    // values 
     printf("These are the values of declared function. \n");
     printf("the value of a is %d \n", a);
     printf("the value of b is %d \n", b);
     printf("the value of c is %d \n\n", c);
    
    printf("the average is %d \n", average);
    
}
