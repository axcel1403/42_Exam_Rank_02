#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0, tmp = 0;;

	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		i--;
		while (i >= 0)
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
			{
				tmp = i;
				i++;
				while (argv[1][i] && (!(argv[1][i] == ' ' || argv[1][i] == '\t')))
				{
					write(1, &argv[1][i], 1);
					i++;
				}
				i = tmp;
			}
			if (i == 0)
			{
				while (argv[1][i] && (!(argv[1][i] == ' ' || argv[1][i] == '\t')))
				{
					write(1, &argv[1][i], 1);
					i++;
				}
				break ;
			}
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
				write(1, &argv[1][i], 1);
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
