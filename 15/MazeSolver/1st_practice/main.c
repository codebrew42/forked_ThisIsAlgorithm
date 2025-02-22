#include "inc/maze_solver.h"

int	handle_error(int flg, char *s1, char *s2, FILE *fp)
{
	//malloc
	if (flg == 0)
		fprintf(stderr, "malloc failed");
	else if (flg == 1)
	{
		perror("reading the map failed");
	}
	else if (flg == 2)
	{
		perror("fgets failed");
	}
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (fp)
		fclose(fp);
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
	d_map = malloc(sizeof(t_map *));
	if (!d_map)
		handle_error(0, NULL, NULL, NULL);
	init_map_scale(d_map, 50, 50);
	read_map(d_map, av[1]);
	// if (!validate_map(d_map))
	// {
	// 	printf("not valid map: path finding impossibled\n");
	// }

}