#include <unistd.h>

int	space_tab(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i = 0, end = 0;

	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		i--;
		while (space_tab(argv[1][i]))
			i--;
		end = i;
		i = 0;
		while (space_tab(argv[1][i]))
			i++;
		while (i <= end)
		{
			if (space_tab(argv[1][i]))
			{
				write(1, &argv[1][i], 1);
				while (i <= end && space_tab(argv[1][i]))
					i++;
			}
			if (argv[1][i])
			{
				write(1, &argv[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
