#include "menger.h"

/**
 * drawSponge - draw each level of the Menger Sponge
 *
 * @level: current level of the Menger Sponge
 * @size: size
 * @row: row index
 * @col: column index
 */
void drawSponge(int level, int size, int row, int col)
{
	int newSize, emptyCenter;

	newSize = size / 3;

	/* Check if position at the center */
	emptyCenter = (row >= newSize && row < 2 * newSize) &&
		      (col >= newSize && col < 2 * newSize);

	if (emptyCenter)
		printf(" ");
	else
	{
		if (level > 0)
			drawSponge(level - 1, newSize, row % newSize, col % newSize);
		else
			printf("#");
	}
}

/**
 * menger - a function that draws a 2D Menger Sponge
 *
 * @level: is the level of the Menger Sponge to draw.
 * If level is lower than 0, function does nothing
 *
 * Return: Nothing
 */
void menger(int level)
{
	int size, i, j;

	if (level < 0)
		return;

	if (level == 0)
	{
		printf("#\n");
		return;
	}

	size = (int)pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			drawSponge(level, size, i, j);
		printf("\n");
	}
}
