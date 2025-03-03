#ifndef MAZESOLVER_H
#define MAZESOLVER_H

#define BUFFER_SIZE 1024
#define INIT_VALUE -1

#define START    'S'    // start 
#define GOAL     'G'    // exist 
#define WAY      ' '    // way1
#define WALL     '#'    // wall
#define MARKED   '+'    // way2

enum	DIRECTION { NORTH, SOUTH, EAST, WEST };
enum	RESULT    { FAIL, SUCCEED }; 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct s_map
{
	int				map_width;
	int				map_height;
	int				start_x;
	int				start_y;
	int				dir_x[4];
	int				dir_y[4];
	char			**map_original;
	int				**map_converted;
	int				**map_marked;
}	t_map;

//main
int	free_int_arr(int **arr, int max_i);
int	handle_error(int flg, void *s, void **d, int fd);

//readmap.c
int		create_map_converted(t_map *m);
int save_2d_map(t_map *m, char *s);
int	read_map_from_input(t_map *m, char *s);


//debug.c
void print_2d_map_char(char **map, int height);
void print_2d_map_int(int **map, int height, int width);

//validate_map.c

int find_start(t_map *m, int *x, int *y);
void set_dir(int x[4], int y[4]);
int create_map_marked(t_map *m);
int validate_map(t_map *m, int x, int y);
#endif