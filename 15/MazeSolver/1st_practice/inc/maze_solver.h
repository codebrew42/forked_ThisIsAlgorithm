#ifndef MAZESOLVER_H
#define MAZESOLVER_H

#define MAX_BUFFER 1024
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

typedef struct s_map
{
	unsigned int	map_width;
	unsigned int	map_height;
	int				**map_saved;
}	t_map;

//main
int	handle_error(int flg, char *s1, char *s2);

//readmap.c
int	read_map(t_map *m, char *map);
int	init_map_scale(t_map *m, int x, int y);

#endif