#include "../inc/minishell.h"

/*
 * for echo commend
 * */

int	builtin_echo(t_cmd *cmd)
{
	int	i;
	int	n_flag;

	if (!cmd || !cmd->arguments)
	{
		perror("commend Erorr");
		return (1);
	}
	i = 0;
	n_flag = 0;
	if (cmd->arguments[i] && ft_strcmp(cmd->arguments[i], "-n") == 0)
	{
		n_flag = 1;
		i++;
	}
	while (cmd->arguments[i])
	{
		printf("%s", cmd->arguments[i]);
		if (cmd->arguments[i + 1])
			printf(" ");
		i++;
	}
	if (n_flag)
		printf("\n");
	return (0);
}

/**
 *for pwd commend
 */

int	builtin_pwd(void)
{
	char	cwd[MAX_PATH_LEN];

	if (getcwd(cwd, MAX_PATH_LEN) == NULL)
	{
		perror("pwd");
		return (ERROR);
	}
	printf("%s", cwd);
	return (SUCCESS);
}

/*
 * cd commend
 * */

int	builtin_cd(t_bash *bash, t_cmd *cmd)
{
	char	*path;
	char	cwd[MAX_PATH_LEN];

	if (!cmd || !cmd->arguments)
		return (ERROR);
	if (!cmd->arguments[1])
		path = get_env_value(bash->s_cmd, "HOME");
	else
		path = cmd->arguments[1];
	if (!path)
	{
		perror("HOME Error");
		return (ERROR);
	}
	if (chdir(path) != 0)
	{
		perror("cd");
		return (ERROR);
	}
	if (getcwd(cwd, MAX_PATH_LEN))
		update_env();
	return (SUCCESS);
}
