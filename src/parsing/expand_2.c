#include "../../include/minishell.h"

int	ft_in_singlea_q(char *s, int pos)
{
	int i;
	int in_single;
	int in_double;

	in_single = 0;
	in_double = 0;
	i = 0;
	while (i < pos)
	{
		if (s[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (s[i] == '"' && !in_single)
	}

	char *ft_get_variable_value(char *var, t_shell *shell)
	{
		char *ft_get_variable_value(char *var, t_shell *shell)
		{
			char *value;
			char *exit_stat_str;

			if (ft_strcmp(var, "?") == 0)
			{
				exit_stat_str = ft_itoa(shell->exit_status);
				return (exit_stat_str);
			}
			value = ft_get_env_value(shell->env, var);
			if (value)
				return (value);
			return (ft_strdup(""));
		}
