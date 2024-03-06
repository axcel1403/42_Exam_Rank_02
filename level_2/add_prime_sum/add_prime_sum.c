#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *nb)
{
	int	num = 0;

	while(*nb >= '0' && *nb <= '9')
	{
		num *= 10;
		num += *nb - '0';
		nb++;
	}
	return (num);
}

int	is_prime(int nb)
{
	int	i = 0;

	i = nb;
	i--;
	if (i == 1)
		return (1);
	while (i > 1)
	{
		if (nb % i == 0)
			return (0);
		i--;
	}
	return (1);
}

void	ft_putnbr(int nb)
{
	char	numbers[] = "0123456789";

	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1, &numbers[nb % 10], 1);
}

int	main(int argc, char **argv)
{
	int	i = 0;
	int	num = 0;

	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		i = num;
		if (!is_prime(num))
			num = 0;
		i--;
		while (i > 1)
		{
			if (is_prime(i))
				num += i;
			i--;
		}
		if (num == 1)
			num = 0;
		ft_putnbr(num);
		write(1, "\n", 1);
	}
	else
		write(1, "0\n", 2);
	return (0);
}
