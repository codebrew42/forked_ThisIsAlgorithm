#include "inc/maze_solver.h"

//cp map to the char**
/*
1. validate the map (pass this case)
	assume that the maps are valid (surrounded by walls)

2. read map from input
	-cp map (1)to char* -(2) create char ** in the struct
		use BUFFER_SIZE (default)
	-save maps height, width

3. created map_converted (int **)
	- for later use (path finding)
*/
int		create_map_converted(t_map *m)
{
	int	i;

	m->map_converted = malloc(m->map_height * sizeof(int *));
	if (!m->map_converted)
		return (handle_error(0, NULL, NULL, 0));
	i = 0;
	while (i < m->map_height)
	{
		m->map_converted[i] = malloc(m->map_width * sizeof(int));
		if (!m->map_converted[i])
	}


}

void	print_2d_map(char **map, int height)
{
	for (int i = 0; i < height; i++)
		printf("%s\n", map[i]); // Print each row of the map
}

// Function to save a 2D map from a string
int save_2d_map(t_map *m, char *s)
{
	int			line_count = 0;
	char		*line_start = s;
	char		*newline;
	ssize_t		length;

	while ((newline = strchr(line_start, '\n')) != NULL)
	{
		line_count++;
		line_start = newline + 1; // Move to the start of the next line
	}
	// If the string does not end with a newline, account for the last line
	if (*line_start != '\0')
		line_count++;
	m->map_original = malloc(line_count * sizeof(char *));
	if (!m->map_original)
		return (handle_error(0, NULL, NULL, 0));
	// Fill the 2D map with strings from the input string
	line_start = s; // Reset to the start of the string
	for (int i = 0; i < line_count; i++)
	{
		newline = strchr(line_start, '\n');
		if (newline)		// Calculate the length of the current line (excluding the newline)
		{
			length = newline - line_start;
			m->map_original[i] = malloc((length + 1) * sizeof(char)); // Allocate exactly the size needed
			if (!m->map_original[i])
				return (handle_error(0, NULL, NULL, 0));
			strncpy(m->map_original[i], line_start, length);
			m->map_original[i][length] = '\0';
			line_start = newline + 1; // Move to the start of the next line
		}
		else		// For the last line without a newline
		{
			m->map_original[i] = strdup(line_start);
			if (!m->map_original[i])
				return (handle_error(0, NULL, NULL, 0));
		}
	}
	m->map_height = line_count;
	m->map_width = (int)length;
	return (0);
}

int	read_map_from_input(t_map *m, char *s)
{
	int		fd;
	char	*buff;
	char	*tmp_map = NULL;
	int		bytes_read;
	int		total;

	if (!m || !s)
		return (1);
	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (handle_error(1, NULL, NULL, fd));
	buff = malloc (BUFFER_SIZE + 1);
	if (!buff)
		handle_error(0, NULL, NULL, fd);
	total = 0;
	while ((bytes_read = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		tmp_map = realloc(tmp_map, total + bytes_read);
		if (!tmp_map)
			handle_error(0, buff, NULL, fd);
		memmove(tmp_map + total, buff, bytes_read);
		total += bytes_read;
	}
	tmp_map[total] = '\0';
	if (bytes_read < 0)
		return (handle_error(2, buff, &tmp_map, fd));
	save_2d_map(m, tmp_map);
	print_2d_map(m->map_original, m->map_height);
	printf("leng[%d], height[%d]", m->map_width, m->map_height);
	return (0);
}
