#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0, start = 0;

	if (argc == 2)
	{
		while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i++;
		start = i;
		while (argv[1][i])
			i++;
		i--;
		while ((argv[1][i] == ' ' || argv[1][i] == '\t') && i > 0)
			i--;
		while (start <= i)
		{
			if (argv[1][start] == ' ' || argv[1][start] == '\t')
			{
				write(1, "   ", 3);
				start++;
				while (start <= i && (argv[1][start] == ' ' || argv[1][start] == '\t'))
					start++;
			}
			else
			{
				write(1, &argv[1][start], 1);
				start++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
