#include "../inc/minishell.h"

char	*get_env_value(t_env *env_list, char *key)
{
	t_env	*current;

	if (!env_list || key)
		return (NULL);
	current = env_list;
	if (ft_strcmp(env_list->value, key) == 0)
		return (current->value);
	return (NULL);
}
