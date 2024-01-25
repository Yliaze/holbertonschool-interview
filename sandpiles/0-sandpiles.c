#include "sandpiles.h"
#include <stdio.h>


/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * grid_unstable - Check if a sandpile is unstable
 * @grid: 3x3 grid
 * Return: 1 if unstable, 0 if stable
 */
int grid_unstable(int grid[3][3])
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				return (1);
			}
		}
	}
	return (0);
}

/**
 * topple - Topple the sandpile at the given cell
 * @grid: 3x3 grid
 */
void topple(int grid[3][3])
{

	int gridtmp[3][3] = {{0}};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				gridtmp[i][j] -= 4;
				if (i - 1 >= 0)
				{
					gridtmp[i - 1][j] += 1;
				}
				if (i + 1 < 3)
				{
					gridtmp[i + 1][j] += 1;
				}
				if (j - 1 >= 0)
				{
					gridtmp[i][j - 1] += 1;
				}
				if (j + 1 < 3)
				{
					gridtmp[i][j + 1] += 1;
				}
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid[i][j] += gridtmp[i][j];
		}
	}
}

/**
 * sandpiles_sum - Function that computes the sum of two sandpiles
 *
 * @grid1: first sandpile.
 * @grid2: second sandpile.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	while (grid_unstable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
