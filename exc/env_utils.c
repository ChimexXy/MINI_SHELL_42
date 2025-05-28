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

int	*update_env(t_bash **list_env, t_env *env)
{
	t_env	*current;
	t_env	*new_env;

	if (!*list_env || !t_env->key || !t_env->value)
		return (ERROR);
	if (!*list_env)
	{
		new_env = creat_env_node(env);
		if (!new_env)
			return (ERROR);
		*env_list = new_env;
		return (SUCCESS);
	}
	current = *list_env;
}
