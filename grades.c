#include <stdio.h>

#define VERI

int main(void)
{
	int score = 80;

#ifdef VERI
	if(score >= 70)
       	{
		printf("Excellent!\n");
		printf("You have passed the mark %d\n", score);
#endif 
	} else {
		
		printf("sorry but you have failed!\n");
	}

        return (0);
}
