/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:12:13 by mozahnou          #+#    #+#             */
/*   Updated: 2025/07/03 23:43:38 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*ft_return_single_dollar(t_expand *exp)
{
	*(exp->i) = exp->start + 1;
	return (ft_strdup("$"));
}

char	*ft_expand_var_value(t_expand *exp)
{
	char	*var_value;

	if (!exp->var_name)
		return (ft_return_single_dollar(exp));
	if (exp->is_quoted)
		return (exp->var_name);
	if (ft_strlen(exp->var_name) == 0)
	{
		free(exp->var_name);
		return (ft_return_single_dollar(exp));
	}
	var_value = ft_get_variable_value(exp->var_name, exp->shell);
	free(exp->var_name);
	return (var_value);
}
