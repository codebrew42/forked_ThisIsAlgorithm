#include "inc/maze_solver.h"

int		convert_map(char c);
int		read_map(t_map *m, char *map);
int		init_map_scale(t_map *m, int x, int y);

int	convert_map(char c)
{
	if (c == WALL)
		return 1;
	return 0;
}

//change map to 0,1
//hint: open()-fopen, gnl, close
int read_map(t_map *m, char *map)
{
	FILE	*fp;
	char	*buffer;
	int		i;
	int		j;
	int		k;
	
	fp = fopen(map, "r"); // "r" : opens a file for reading
	if (!fp)
		return (handle_error(1, NULL, NULL, NULL));
	buffer = malloc((m->map_height * m->map_width) + 1);
	if (!buffer)
	{
		fclose(fp);
		return (handle_error(0, NULL, NULL, NULL));
	}
	j = 0;
	//fgets : read
	while (fgets(buffer, sizeof(buffer), fp))
	{
		k = 0;
		i = 0;
		while (buffer[k] && buffer[k] != '\n')
		{
			m->map_converted[j][i] = convert_map(buffer[k]);
			printf("buffer[%d]=[%c]  is converted to converted[%d][%d]", k, buffer[i], j, i);
			if (buffer[k] == '\n' || buffer[k + 1] == '\0')
				m->map_converted[j][i++] = '\0';
			i++;
			k++;
		}
		j++;
	}
	if (ferror(fp))
		return (handle_error(2, buffer, NULL, fp));
	fclose(fp);
	free(buffer);
	return (0);
}

//temporary func, fix : get x and y from map
int	init_map_scale(t_map *m, int x, int y)
{
	unsigned int		i;

	m->map_width = x;
	m->map_height = y;
	m->map_converted = malloc (m->map_height * sizeof(int *));
	if (!m->map_converted)
		return (handle_error(0, NULL, NULL, NULL));
	i = 0;
	while (i < m->map_height)
	{
		m->map_converted[i] = malloc (m->map_width * sizeof(int));
		if (!m->map_converted[i])
		{
			while (m->map_converted[--i])
				free(m->map_converted[i]);
			free(m->map_converted);
			return (handle_error(0, NULL, NULL, 0));
		}
	}
	return (0);
}