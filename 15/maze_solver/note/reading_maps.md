## how to use enum arr?

#### example 1
```h
#ifndef MAZESOLVER_H
#define MAZESOLVER_H

enum	DIRECTION { NORTH, SOUTH, EAST, WEST };
enum	RESULT    { FAIL, SUCCEED }; 
```

```c
int		move(int x, int y, DIRECTION dir)
{
	switch (dir)
	{
		case NORTH:
			return y - 1;
		case SOUTH:
			return y + 1;
		case EAST:
			return x + 1;
		case WEAST:
			return x - 1;
	}
	return (-1);
}

int		main()
{
	int x = 0;
	int y = 0;
	DIRECTION next = NORTH;
	char maze[10][10];

	//move next
	y = move(x, y, next);
	if (!try_to_move(maze, x, y))
		printf("you hit a wall!\n");
}


```