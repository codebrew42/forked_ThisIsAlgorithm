#include "inc/maze_solver.h"

/* how to validate recursively? [backtracking]

steps
[1]find_start(m, *x, *y)
	change value directly with pointer x,y
[1]move_func(m, x, y)
	if (WALL, outside map)
		early return (1)
	if (GOAL)
		return (0) //means valid
	while (i <= 4)
		new_x <- x
		new_y <- y
		if (!validate_map(m, new_x, new_y))
			return (0)


early ret :
base case(normal ret) : if(GOAL found) then {return 0}

*/
int find_start(t_map *m, int *x, int *y);
void set_dir(int x[4], int y[4]);
int create_map_marked(t_map *m);
int validate_map(t_map *m, int x, int y);



int find_start(t_map *m, int *x, int *y)
{
	int i;
	int j;

	i = 0;
	while (i < m->map_height)
	{
		j = 0;
		while (j < m->map_width)
		{
			if (m->map_converted[i][j] == 2)
			{
				*x = j;
				*y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void set_dir(int x[4], int y[4])
{
	x[0] = 1;
	x[1] = 0;
	x[2] = -1;
	x[3] = 0;
	y[0] = 0;
	y[1] = 1;
	y[2] = 0;
	y[3] = -1;
}

int create_map_marked(t_map *m)
{
	int i;

	m->map_marked = malloc(m->map_height * sizeof(int *));
	if (!m->map_marked)
		return (handle_error(0, NULL, (void **)m->map_marked, 0));
	i = 0;
	while (i < m->map_height)
	{
		m->map_marked[i] = malloc(m->map_width * sizeof(int));
		if (!m->map_marked[i])
			return (handle_error(0, NULL, (void **)m->map_marked, 0));
		memcpy(m->map_marked[i], m->map_converted[i], m->map_width * sizeof(int));
		i++;
	}
	printf("map_marked:\n");
	print_2d_map_int(m->map_marked, m->map_height, m->map_width);
	return (0);
}

int validate_map(t_map *m, int x, int y)
{
	int i;


	if (x >= m->map_width || y >= m->map_height || x < 0 || y < 0)
		return (1);
	else if (x == m->map_width && y == m->map_height)
		return (1);
	else if (m->map_converted[y][x] == 1)
		return (1);
	else if (m->map_marked[y][x] == 2 && x != m->start_x && y != m->start_y)
		return (1);
	else if (m->map_converted[y][x] == 3)
	{
		printf("A valid way found!\n map_marked:\n");
		print_2d_map_int(m->map_marked, m->map_height, m->map_width);
		return (0);
	}
	else if (m->map_converted[y][x] == 0)
	{
		printf("approaching to map[%d][%d]\n", y, x);
	}
	m->map_marked[y][x] = 2;
	printf("MARKED: map_marked[%d][%d] = %d\n", y, x, m->map_marked[y][x]);
	print_2d_map_int(m->map_marked, m->map_height, m->map_width);
	usleep(600000);
//	printf("approached: m->map_marked[%d][%d] is marked as 2\n", y, x);
	i = 0;
	while (i < 4)
	{
		if (!validate_map(m, x + m->dir_x[i], y + m->dir_y[i]))
			return (0);
		i++;
	}
	//unmark if no path found(backtracking)
	m->map_marked[y][x] = m->map_converted[y][x];
	printf("UNMARKED: map_marked[%d][%d] = %d\n", y, x, m->map_marked[y][x]);

	return (1);
}
