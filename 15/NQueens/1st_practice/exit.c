#include "inc/nqueens.h"

int		free_int_arr(int **arr, int max_idx);
int		print_err(int flag, char *s);

// void	free_map_data(t_map *m)
// {

// }

int	free_int_arr(int **arr, int max_idx)
{
	if (!arr)
		return (0);
	while (max_idx >= 0)
	{
		if (arr[max_idx])
			free(arr[max_idx]);
		max_idx--;
		return (0);
	}
	free (arr);
	return (1);
}

int	print_err(int flag, char *s)
{
	if (flag == 0)
		printf("Error: %s\n", s);
	if (flag == 1)
		perror("malloc");
	return (1);
}

