#include "inc/nqueens.h"

int	main(int ac, char **av)
{
//	int		size;
	t_map	*m;

	if (ac != 2)
		return (print_err(0, "One input is not given"));
	if (!av)
		return (1);
	m = malloc(sizeof(t_map));
	if (!m)
		return (print_err(1, "Malloc for t_map failed"));

	if (create_board(m, av[1]))
		return (1);
	printf("first board is ready\n");
	print_2d_arr(m, m->solutions->board);
	// if (!get_solutions(m))
	// 	printf("solution not found");

	return (0);
}