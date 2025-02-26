#include "inc/nqueens.h"

int		create_board(t_map *m, char *s);
int		validate_size(char *s);
int		init_solution_data(t_solutions *s, int n);
void	put_blank(t_map *m, int **arr);
int		ft_atoi(char *s);

int	create_board(t_map *m, char *s)
{
	int		size;
//	int		i;
//	int		k;

	//rm
	if (!m)
		printf("dog");
	//rm
	size = validate_size(s);
	if (size <= 0 || init_solution_data(m->solutions, size))
		return (1);
	m->size = size;
	put_blank(m, m->solutions->board);
	return (0);
}

int	validate_size(char *s)
{
	int		size;

	size = ft_atoi(s);
	if (size <= 0)
		return (print_err(0, "Invalid Number is Given"));
	return (size);
}

int	init_solution_data(t_solutions *s, int n)
{
	int		i;

	s = malloc(sizeof(t_solutions *));
	if (!s)
		return (print_err(1, NULL));
	i = 0;
	s->board = malloc(n * sizeof(int *));
	if (!s->board)
		return (print_err(1, NULL));
	while (i < n)
	{
		s->board[i] = malloc(n * sizeof(int));
		if (!s->board[i])
			return (free_int_arr(s->board, i - 1));
		i++;
	}
	return (0);
}

void	put_blank(t_map *m, int **arr)
{
	int		i;
	int		j;

	i = 0;
	while (i < m->size)
	{
		j = 0;
		while (j < m->size)
		{
			arr[i][j] = BLANK;
			j++;
		}
		i++;
	}
}

int	ft_atoi(char *s)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (!s)
		return(-1);
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 58)
			return (-1);
		res = res * 10 + (s[i] - 48);
		i++;
	}
	return (res);
}