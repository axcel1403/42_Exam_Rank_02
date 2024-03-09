#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0, last = 0, end = 0, flag = 0;

	if (argc >= 2)
	{
		while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i++;
		last = i;
		while (argv[1][i] && (!(argv[1][i] == ' ' || argv[1][i] == '\t')))
			i++;
		end = i;
		while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i++;
		if (argv[1][i])
			flag = 1;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
			{
				write(1, &argv[1][i], 1);
				while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
					i++;
				i--;
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
		if (flag == 1 && (argv[1][i - 1] != ' ' && argv[1][i - 1] != '\t'))
			write(1, " ", 1);
		while (last < end)
		{
			write(1, &argv[1][last], 1);
			last++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
