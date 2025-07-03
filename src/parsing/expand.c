/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:42:20 by mozahnou          #+#    #+#             */
/*   Updated: 2025/07/03 23:18:36 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*ft_extract_unquoted_var(char *str, int *i)
{
	int		start;
	int		len;
	char	*var_name;

	start = *i;
	if (!(ft_isalpha(str[*i]) || str[*i] == '_'))
		return (ft_strdup(""));
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	len = *i - start;
	if (len == 0)
		return (ft_strdup(""));
	var_name = malloc(len + 1);
	ft_strlcpy(var_name, str + start, len + 1);
	var_name[len] = '\0';
	return (var_name);
}

static char	*ft_extract_var_name(char *str, int *i)
{
	if (str[*i] == '?')
	{
		(*i)++;
		return (ft_strdup("?"));
	}
	if (str[*i] == '"' || str[*i] == '\'')
		return (ft_extract_quoted_var(str, i));
	return (ft_extract_unquoted_var(str, i));
}

char	*ft_expand_dollar(char *s, int *i, t_shell *shell)
{
	t_expand	exp;

	exp.start = *i;
	(*i)++;
	exp.is_quoted = (s[*i] == '"' || s[*i] == '\'');
	exp.var_name = ft_extract_var_name(s, i);
	exp.i = i;
	exp.shell = shell;
	return (ft_expand_var_value(&exp));
}

static char	*ft_append_char(char *str, char c)
{
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	tmp = malloc(len + 2);
	ft_strlcpy(tmp, str, len + 1);
	tmp[len] = c;
	tmp[len + 1] = '\0';
	free(str);
	return (tmp);
}

char	*ft_expand_variables(char *str, t_shell *shell)
{
	char	*result;
	int		i;

	result = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1] == '$' && !ft_in_singlea_q(str, i))
		{
			result = ft_append_char(result, '$');
			i += 2;
		}
		else if (str[i] == '$' && !ft_in_singlea_q(str, i))
			result = ft_handle_dollar_expansion(str, &i, result, shell);
		else
		{
			result = ft_append_char(result, str[i]);
			i++;
		}
	}
	return (result);
}
