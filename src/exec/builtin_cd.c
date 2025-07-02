#include "../../include/minishell.h"

static int	ft_cd_handle_path(char **args, char **path)
{
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
		*path = home;
	}
	else
		*path = args[1];
	return (0);
}

static int	ft_cd_change_dir(char *path)
{
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

int	ft_builtin_cd(t_shell *shell, char **args)
{
	char	*path;
	char	cwd[MAX_PATH];
	char	old_pwd[MAX_PATH];

	if (getcwd(old_pwd, sizeof(old_pwd)) == NULL)
		old_pwd[0] = '\0';
	if (ft_cd_handle_path(args, &path) != 0)
		return (1);
	if (ft_cd_change_dir(path) != 0)
		return (1);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		if (*old_pwd)
			ft_set_env_value(shell, "OLDPWD", old_pwd);
		ft_set_env_value(shell, "PWD", cwd);
	}
	return (0);
}
