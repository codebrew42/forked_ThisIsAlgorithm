#ifndef NQUEENS_H
#define NQUEENS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_solutions
{
	int						size;
	int						*column;
	int						row;
	int						nbr_solutions;
	struct s_solutions		*next;
}		t_solutions;

//main.c
int		create_blank_board(t_solutions **s, int size);
int		create_columns(int **c, int size);

//free.c
void	free_int_arr(int *arr, int size);
void	free_solutions(t_solutions *s);

#endif