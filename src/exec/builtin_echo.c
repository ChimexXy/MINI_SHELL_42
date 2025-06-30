#include "../../include/minishell.h"

static int	is_valid_n_flag(char *arg)
{
	int	j;

	if (arg[0] != '-' || arg[1] == '\0')
		return (0);
	j = 1;
	while (arg[j])
	{
		if (arg[j] != 'n')
			return (0);
		j++;
	}
	return (j > 1);
}

static int	process_n_flags(char **args)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	while (args[i])
	{
		if (is_valid_n_flag(args[i]))
		{
			newline = 0;
			i++;
		}
		else
			break ;
	}
	return (i | (newline << 16));
}

int	ft_builtin_echo(char **args)
{
	int	i;
	int	newline;
	int	first_arg;
	int	result;

	result = process_n_flags(args);
	i = result & 0xFFFF;
	newline = (result >> 16) & 1;
	first_arg = 1;
	while (args[i])
	{
		if (!first_arg)
			ft_putstr_fd(" ", 1);
		ft_putstr_fd(args[i], 1);
		first_arg = 0;
		i++;
	}
	if (newline)
		ft_putstr_fd("\n", 1);
	return (0);
}
