#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * alloc_grid - creates a 2 dimensional array of integers
 * @width: number of columns
 * @height: number of rows
 *
 * Return: pointer to the 2D array, or NULL if width or height
 * is less than or equal to 0 or if memory allocation fails
 */
int **alloc_grid(int width, int height)
{
	int **grid, i = 0;

	if (width <= 0 || height <= 0)
		return (NULL);
	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
			grid[i] = malloc(sizeof(int) * width);
	for (i = 0; i < height; i++)
	{
	for (int j = 0; j < width; j++)
		grid[i][j] = 0;
	}
	return (grid);
}
