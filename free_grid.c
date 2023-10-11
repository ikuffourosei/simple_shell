#include <simpleshell.h>

/**
 * free_grid - frees a 2D grid previously created by alloc_grid
 * @grid: the 2D array to be freed
 * @height: the number of rows in the grid
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height <= 0)
	{
		return;
	}
	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
