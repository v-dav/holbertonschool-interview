#include "sandpiles.h"

/**
 * print_grid2 - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_grid2(int grid[3][3])
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
 * add_matrix - Computes brut sum of two 3x3 matrixes
 *
 * @grid1: Left 3x3 grid of integers
 * @grid2: Right 3x3 grid of integers
 *
 * Return: void
 */
void add_matrix(int grid1[3][3], int grid2[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}

/**
 * toppling - Reequlibrates sandpile
 *
 * @grid1: Sandpile to reequlibrate
 *
 * Return: void
 */
void toppling(int grid1[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				if (i - 1 >= 0)
					grid1[i - 1][j]++;

				if (j - 1 >= 0)
					grid1[i][j - 1]++;

				if (j + 1 < 3)
					grid1[i][j + 1]++;

				if (i + 1 < 3)
					grid1[i + 1][j]++;

				grid1[i][j] = grid1[i][j] - 4;
			}
		}
	}
}
/**
 * sandpiles_sum - Computes sum of two 3x3 stable sandpiles
 * Description: We assume that grid1 and grid2 are stable
 * (none of its cells contains more than 3 grains).
 * When function is done the gird1 must be stable.
 * grid1 must be printed before each toppling round,
 * only if it is unstable.
 *
 * @grid1: Left 3x3 grid of integers, with max 3 (stable)
 * @grid2: Right 3x3 grid of integers, with max 3 (stable)
 *
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_matrix(grid1, grid2);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				printf("=\n");
				print_grid2(grid1);
				toppling(grid1);
				i = 0;
				j = 0;
				break;
			}
		}
	}
}
