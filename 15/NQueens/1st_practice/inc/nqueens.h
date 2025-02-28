#ifndef NQUEENS_H
#define NQUEENS_H

#define BLANK 0
#define MARKED 1
#define UNMARKED 2
#define QUEEN 9

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct		s_solutions;

typedef struct s_map
{
	int					size;
	int					nbr_solutions;
	struct s_solutions	*solutions;
}	t_map;

typedef struct s_solutions
{
	int					nbr_queens;
	int					**board;
	struct s_solutions	*next;
}	t_solutions;

//ready.c
int		create_board(t_map *m, char *s);
int		validate_size(char *s);
int		init_solution_data(t_solutions *s, int n);
void	put_blank(t_map *m, int **arr);
int		ft_atoi(char *s);


//exit.c
int		free_int_arr(int **arr, int max_idx);
int		print_err(int flag, char *s);

//print.c
void	print_2d_arr(t_map *m, int **a);
//solution.c
int		get_solutions(t_map *m);

#endif