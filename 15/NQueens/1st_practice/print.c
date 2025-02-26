#include "inc/nqueens.h"

void	print_2d_arr(t_map *m, int **a);

void	print_2d_arr(t_map *m, int **a)
{
	int	i = 0;
	int	j;
	while (i < m->size)
	{
		j = 0;
		while (j < m->size)
			printf("%d", a[i][j++]);
		printf("\n");
		i++;
	}
}