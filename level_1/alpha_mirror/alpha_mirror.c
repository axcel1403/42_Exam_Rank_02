#include <unistd.h>

int	upper(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int	lower(char c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (upper(argv[1][i]))
				argv[1][i] = 'Z' - (argv[1][i] - 'A');
			else if (lower(argv[1][i]))
				argv[1][i] = 'z' - (argv[1][i] - 'a');
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
