#include "inc/maze_solver.h"


int	free_int_arr(int **arr, int max_i)
{
	if (!arr || !*arr)
		return (1);
	if (*arr)
	{
		while (max_i-- > 0)
		{
			free(arr[max_i]);
		}
	}
	free (arr);
	return (0);
}
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
	t_map	*m;

	if (ac != 2)
	{
		printf("Map is not given\n");
		return (0);
	}
	m = malloc(sizeof(t_map));
	if (!m)
		handle_error(0, NULL, NULL, 0);
	if (av[1] == NULL)
		return 1; 
	if (read_map_from_input(m, av[1]))
	{
		free(m);
		return (1);
	}
	if (create_map_converted(m))
	{
		free(m);
		return (1);
	}
	printf("map_converted:\n");
	print_2d_map_int(m->map_converted, m->map_height, m->map_width);
	if (!find_start(m, &m->start_x, &m->start_y))
		return (1);

	printf("start_x[%d], start_y[%d] found\n", m->start_x, m->start_y);
	set_dir(m->dir_x, m->dir_y);
	if (create_map_marked(m))
		return (1);
	if (!validate_map(m, m->start_x, m->start_y))
		printf("valid map found: path finding possible\n");
	free (m);
	return (0);
}