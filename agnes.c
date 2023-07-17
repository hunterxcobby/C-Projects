#include <stdlib.h>
#include <stdio.h>

/**
 * Main - Entry point
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 * struct dog - structures a new dog
 * Return: pointer to the new dog (Success), NULL otherwise
 */

struct dog
{
	char *owner;
	char *name;
	float age;
};

struct dog *new_dog(char *name, char *owner, float age)
{
	struct dog *new_dog = malloc(sizeof(struct dog));
	if (new_dog == NULL) {
		return NULL;  /* Memory allocation failed*/
	}

	new_dog->name = name;
	new_dog->owner = owner;
	new_dog->age = age;

	return (new_dog);
}

int main(void)
{
	struct dog *dog;
	dog = new_dog("Jimmy", "Agnes", 10);
	if (dog == NULL)
	{
		return (1);  /*Error in creating the dog struct*/
	}

	printf("Name: %s\n", dog->name);
	printf("Owner: %s\n", dog->owner);
	printf("Age: %.1f\n", dog->age);

	free(dog);  /*Free dynamically allocated memory*/

	return (0);
}

