#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - Allocates a 2-dimensional grid of integers
 * @width: The width of the grid
 * @height: The height of the grid
 *
 * Return: Pointer to the allocated grid, or NULL if it fails
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	/* Allocate memory for the rows */
	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);

	/* Allocate memory for the columns and initialize to 0 */
	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width);
		if (grid[i] == NULL)
		{
			/* Free the previously allocated memory */
			for (j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}

		/* Initialize the elements to 0 */
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}
