#include "nqueens.h"

void	free_int_arr(int *arr, int size)
{
	while (--size >= 0)
		free(arr);
}

void	free_solutions(t_solutions *s)
{
	int				size = s->size;
	t_solutions		*tmp = s;
	t_solutions		*next;

	while (tmp)
	{
		next = tmp->next;
		free(tmp->column);
		free(tmp);
		tmp = next;
	}
}
