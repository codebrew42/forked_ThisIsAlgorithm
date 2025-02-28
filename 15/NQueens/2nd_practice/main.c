#include "nqueens.h"

int		*create_tmp_columns(int size)
{


}

t_solutiuons	*create_solutions(int size)
{

}

int	ft_atoi(char *s)
{


}
int		main(int ac, char **av)
{
	int				size;
	t_solutions		*s;
	int				*columns;

	if (ac != 2)
	{
		printf("Err:input not given");
		return (1);
	}
	if (size = ft_atoi(av[1]) <= 0)
	{
		printf("Err:input not positive");
		return (1);
	}
	//fix: return valu!
	if (!create_solutions(s, size))
		return (1);
	if (!create_tmp_columns(columns, size))
		return (1);
	if (find_solutions(s, columns))
		print_solutions(s);
	else
		printf("solutions not found\b");
	free_int_arr(columns);
	free_solutions(s);
	return (0);
}