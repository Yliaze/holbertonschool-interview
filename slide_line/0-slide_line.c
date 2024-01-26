#include "slide_line.h"
#include <stdio.h>

/**
 * slide_line - Slides and merges an array of integers
 * @line: Points to an array of integers
 * @size: Number of elements in the array
 * @direction: direction to slide & merge SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 on success, 0 on failure
 *
 */
int slide_line(int *line, size_t size, int direction)
{

	size_t i, j, merged;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size; i++)
		{
			if (line[i] != 0)
			{
				for (j = i + 1; j < size && line[j] == 0; j++)
					continue;
				if (j < size && line[i] == line[j])
				{
					line[i] *= 2;
					line[j] = 0;
				}
			}
		}
		merged = 0;
		for (i = 0; i < size; i++)
		{
			if (line[i] != 0)
				line[merged++] = line[i];
		}
		while (merged < size)
			line[merged++] = 0;
	}
	return (1);
}
