#include <stdlib.h>

int	delimiter(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	count_words(char *str)
{
	int	i = 0;
	int	count = 0;

	while (delimiter(str[i]))
		i++;
	while (str[i])
	{
		if (delimiter(str[i]))
		{
			count++;
			while (str[i] && delimiter(str[i]))
				i++;
			i--;
		}
		i++;
	}
	count++;
	return (count);
}

void	cpy_words(char **tab, char *str)
{
	int	i = 0, j = 0, k = 0;;

	while (delimiter(str[i]))
		i++;
	while (str[i])
	{
		j = 0;
		while (str[j] && (!(delimiter(str[j]))))
			j++;
		tab[k] = malloc(sizeof(char) * j + 1);
		j = 0;
		while (str[i] && (!(delimiter(str[i]))))
		{
			tab[k][j] = str[i];
			i++;
			j++;
		}
		tab[k][j] = '\0';
		k++;
		if (str[i] == '\0')
			return ;
		while (delimiter(str[i]))
			i++;
	}
	tab[k] = NULL;
}

char	**ft_split(char *str)
{
	int		nb_words = 0;
	char	**tab = NULL;

	nb_words = count_words(str);
	tab = malloc(sizeof(char *) * (nb_words + 1));
	if (!tab)
		return (NULL);
	cpy_words(tab, str);
	if (!tab)
		return (NULL);
	return (tab);
}

/*int	main(void)
{
	int		i = 0;
	char	*str = "  Ceci est un test";
	char	**tab = NULL;

	tab = ft_split(str);
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}*/
