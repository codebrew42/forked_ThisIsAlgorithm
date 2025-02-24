# flow chart

#### part1 : required
```c
	//measure map size -> malloc -> save map data to struct
	void	read_map();

	//to check (1)validity of the map (2)possibility of finding a exit
	void	validate_map();

	// only then, open
	void	open_map();
```

#### part2 : not neccessary for this
```c
	// from the user
	void	get_next_step();

	// is it the wall?
	void	try_to_move();

	//update actual x,y pos
	void	move();
```


# DAY 1 (2025.02.22)
- to fix: read_line , understand fgets and rewrite this

# DAY 3 (2025.02.25)
- path finding was possible, but somehow one way is skipped and not marked
```c
A valid way found!
 map_marked:
1311111111111111
1222222222022221
1111011111111121
1000011100022221
1011011101121111
1011011100121111
1011111101122221
1000000101111121
1011111101111121
1010001000222101
1110101111112121
1010100000002121
1010111111112121
1011111111112121
1000000000002221
1111111111111111
valid map found: path finding possible
```