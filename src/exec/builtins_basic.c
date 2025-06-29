#include "../../include/minishell.h"

int	is_valid_n_option(char *str)
{
	int	i;

	if (!str)
		return (0);
	if (str[0] != '-')
		return (0);
	if (str[1] == '\0') // if it's just "-"
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}


int	ft_builtin_echo(char **args)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	while (args[i] && is_valid_n_option(args[i]))
	{
		newline = 0;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (newline)
		ft_putchar_fd('\n', 1);
	return (0);
}



int	ft_builtin_cd(char **args)
{
	char	*path;
	char	*home;

	if (args[1] && args[2])
	{
		ft_print_command_error("cd", TOO_MANY_ARGS);
		return (1);
	}
	if (!args[1])
	{
		home = getenv("HOME");
		if (!home)
		{
			ft_print_command_error("cd", "HOME not set");
			return (1);
		}
		path = home;
	}
	else
		path = args[1];
	if (chdir(path) == -1)
	{
		if (errno == ENOENT)
			ft_print_command_error("cd", NO_SUCH_FILE);
		else if (errno == ENOTDIR)
			ft_print_command_error("cd", NOT_A_DIRECTORY);
		else
			ft_print_file_error(path);
		return (1);
	}
	return (0);
}

int	ft_builtin_pwd(void)
{
	char	cwd[MAX_PATH];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		ft_print_file_error("pwd");
		return (1);
	}
	ft_putendl_fd(cwd, 1);
	return (0);
}

int	ft_builtin_env(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->env[i])
	{
		ft_putendl_fd(shell->env[i], 1);
		i++;
	}
	return (0);
}

int	ft_builtin_unset(t_shell *shell, char **args)
{
	int	i;

	if (!args[1])
		return (0);
	i = 1;
	while (args[i])
	{
		ft_unset_env_value(shell, args[i]);
		i++;
	}
	return (0);
}
