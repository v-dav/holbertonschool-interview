#include "sandpiles.h"

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
}
