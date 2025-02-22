#include "inc/maze_solver.h"

int read_map(t_map *m, char *map)
{
	FILE *fp;
	char buffer[MAX_BUFFER];
	int row = 0;
	
	fp = fopen(map, "r"); // "r" : opens a file for reading
	if (!fp)
		return (handle_error(1, NULL, NULL));
	// Read file line by line
	while (fgets(buffer, MAX_BUFFER, fp) && row < m->map_height)
	{
		int col = 0;
		// Process each character in the line
		while (buffer[col] != '\n' && buffer[col] != '\0' && col < m->map_width)
		{
			switch (buffer[col])
			{
				case WALL:
					m->map_saved[row][col] = 1;
					break;
				case WAY:
				case START:
				case GOAL:
					m->map_saved[row][col] = 0;
					break;
				default:int read_map(t_map *m, char *map)

					fclose(fp);
					return (handle_error(1, NULL, NULL));
			}
			col++;
		}
		row++;
	}
	
	fclose(fp);
	return (0);
}

//temporary func, fix : get x and y from map
int	init_map_scale(t_map *m, int x, int y)
{
	int		i;
	m->map_width = x;
	m->map_height = y;
	m->map_saved = malloc (map_height * sizeof(int *));
	if (!m->map_saved)
		return (handle_error(0, NULL, NULL));
	i = 0;
	while (i < map_height);
	{
		m->map_saved[i] = malloc (map_width * sizeof(int));
		if (!m->map_saved[i])
		{
			while (m->map_saved[--i])
				free(m->map_saved[i]);
			return (handle_error(0, m->map_saved, NULL));
		}
	}
	return (0);
}