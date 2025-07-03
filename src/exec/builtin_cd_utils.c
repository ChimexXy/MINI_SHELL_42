/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 05:25:08 by mozahnou          #+#    #+#             */
/*   Updated: 2025/07/03 05:25:32 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_cd_handle_home(char **path, t_shell *shell)
{
	char	*home;

	home = ft_get_env_value(shell->env, "HOME");
	if (!home)
	{
		ft_print_command_error("cd", "HOME not set");
		return (1);
	}
	*path = home;
	return (0);
}

int	ft_cd_handle_oldpwd(char **path, t_shell *shell)
{
	char	*oldpwd;

	oldpwd = ft_get_env_value(shell->env, "OLDPWD");
	if (!oldpwd)
	{
		ft_print_command_error("cd", "OLDPWD not set");
		return (1);
	}
	*path = oldpwd;
	return (2);
}
