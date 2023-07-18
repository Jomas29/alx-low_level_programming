#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog structure
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 *
 * Return: Pointer to the newly created dog structure, or NULL on failure
 *
 * Description: This function creates a new dog structure, allocates memory for
 *              the name and owner strings, makes copies of the provided strings,
 *              sets the age, and returns a pointer to the created dog structure.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *newDog;
	char *nameCopy, *ownerCopy;

	/* Allocate memory for the dog structure */
	newDog = malloc(sizeof(dog_t));
	if (newDog == NULL)
		return (NULL);

	/* Allocate memory and make copies of the name and owner strings */
	nameCopy = malloc(strlen(name) + 1);
	ownerCopy = malloc(strlen(owner) + 1);
	if (nameCopy == NULL || ownerCopy == NULL)
	{
		free(newDog);
		free(nameCopy);
		free(ownerCopy);
		return (NULL);
	}

	/* Copy the name and owner strings */
	strcpy(nameCopy, name);
	strcpy(ownerCopy, owner);

	/* Set the name, age, and owner */
	newDog->name = nameCopy;
	newDog->age = age;
	newDog->owner = ownerCopy;

	return (newDog);
}
