#include <unistd.h>

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

int	check_doubles(char *str,char c, int index)
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

int main(int argc, char **argv)
{
	int	i = 0;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		if (ft_strcmp(argv[2], argv[1][i]) == 1 && check_doubles(argv[1], argv[1][i], i) == 0)
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return(0);
}
