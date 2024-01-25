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
int grid_unstable(int grid[3][3]) {

    // loop trough grids cells
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] > 3) {
                return 1; // Unstable
            }
        }
    }
    return 0; // Stable
}

/**
 * topple - Topple the sandpile at the given cell
 * @grid: 3x3 grid
 * @i: row index
 * @j: column index
 */
void topple(int grid[3][3]) {

    int gridtmp[3][3] = {{0}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] > 3) {
                gridtmp[i][j] -= 4;
                if (i - 1 >= 0) {
                    gridtmp[i - 1][j] += 1; // Top cell
                }  
                if (i + 1 < 3) {
                    gridtmp[i + 1][j] += 1; // Bottom cell
                } 
                if (j - 1 >= 0) {
                    gridtmp[i][j - 1] += 1; // Left cell
                }
                if (j + 1 < 3) {
                    gridtmp[i][j + 1] += 1; // Right cell
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Add the values of corresponding cells
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
void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    
    // loop trough grids cells
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Add the values of corresponding cells
            grid1[i][j] += grid2[i][j];
        }
    }

    // Topple until grid1 is stable
    while (grid_unstable(grid1)) {
        // Print grid before topple
        printf("=\n");
        print_grid(grid1);
        topple(grid1);
    }
}
