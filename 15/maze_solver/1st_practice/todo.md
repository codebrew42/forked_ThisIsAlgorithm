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