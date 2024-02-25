#include <unistd.h>

int	ft_checkdoubles(char *str, char c, int index)
{
	int	i = 0;
	while (str[i] && i < index)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *str, char c)
{
	int	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int	i = 0;
	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		if (ft_checkdoubles(argv[1], argv[1][i], i) == 0)
			write(1, &argv[1][i], 1);
		i++;
	}
	i = 0;
	while (argv[2][i])
	{
		if (ft_strcmp(argv[1], argv[2][i]) == 0 && ft_checkdoubles(argv[2], argv[2][i], i) == 0)
			write (1, &argv[2][i], 1);
		i++;
	}
	write (1, "\n", 1);
	return (0);
}


