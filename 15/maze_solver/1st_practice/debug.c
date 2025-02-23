#include "inc/maze_solver.h"

void	print_2d_map_int(int **map, int height, int width)
{
	int i = 0;
	int j = 0;

	while (i < height)
	{
		j = 0;
		while (j < width)
			printf("%d", map[i][j++]);
		printf("\n");
		i++;
	}
}

void	print_2d_map_char(char **map, int height)
{
	for (int i = 0; i < height; i++)
		printf("%s\n", map[i]); // Print each row of the map
}