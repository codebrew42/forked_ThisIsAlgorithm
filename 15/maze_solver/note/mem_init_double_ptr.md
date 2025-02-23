### why init this way doesn't work?


```c
typedef struct s_map
{
	unsigned int	map_width;
	unsigned int	map_height;
	int				**map_saved;
}	t_map;

void	init_map(t_map *m)
{
	m->map_width = 10;
	m->map_height = 10;
	m->map_saved[10][10];
}

```

the following line is incorrect:

```c
m->map_saved[10][10];
```

### Issues:

1. **No Memory Allocation:**

   - `map_saved` is a pointer to a pointer (`int **map_saved`), meaning it needs to be allocated memory before use.
   - The line `m->map_saved[10][10];` does not allocate memory; it only tries to access an index that doesn't exist yet.

2. **Segmentation Fault Risk:**

   - Since `map_saved` is not pointing to valid memory, attempting to access `m->map_saved[10][10]` will likely cause a segmentation fault (crash).

---

## Correct Way to Initialize `map_saved`

### 1. Allocate Memory for Rows

```c
m->map_saved = malloc(m->map_height * sizeof(int *));
```

- This allocates space for an array of pointers, where each pointer will point to a row.

### 2. Allocate Memory for Columns

```c
for (unsigned int i = 0; i < m->map_height; i++)
    m->map_saved[i] = malloc(m->map_width * sizeof(int));
```

- By following these steps, you ensure that map\_saved is correctly allocated and ready to use!

### tips
#include <stdio.h>

int main(void)
{
    printf("sizeof(int) = %lu bytes\n", sizeof(int)); //int size = 4 bytes
    printf("sizeof(char) = %lu bytes\n", sizeof(char)); //char size = 1 byte
    return 0;
}

