#include "inc/maze_solver.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	handle_error(int flg, void *s, void **d, int fd)
{
	if (flg == 0)
		fprintf(stderr, "malloc failed\n");
	else if (flg == 1)
		perror("opening the map failed");
	else if (flg == 2)
		perror("reading the map failed");
	else if (flg == 3)
		perror("fgets failed");
	if (s)
		free(s);

	if (d)
	{
		void **tmp = d;
		while (*tmp)
			free(*tmp++);
		free(d);
	}

	if (fd)
		close(fd);
	return (1);
}


int	main(int ac, char **av)
{
	t_map	*d_map;

	if (ac != 2)
	{
		printf("Map is not given\n");
		return (0);
	}
	d_map = malloc(sizeof(t_map));
	if (!d_map)
		handle_error(0, NULL, NULL, 0);
	if (av[1] == NULL)
		return 1; 
	if (read_map_from_input(d_map, av[1]))
	{
		free(d_map);
		return (1);
	}

	// if (!validate_map(d_map))
	// {
	// 	printf("not valid map: path finding impossibled\n");
	// }
	free (d_map);
	return (0);
}