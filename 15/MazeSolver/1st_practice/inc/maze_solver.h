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
	char			**map_original;
	int				**map_converted;
}	t_map;

//main
int	handle_error(int flg, void *s, void **d, int fd);

//readmap.c
void print_2d_map(char **map, int height);
int save_2d_map(t_map *m, char *s);
int	read_map_from_input(t_map *m, char *s);

#endif