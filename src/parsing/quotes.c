/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:42:47 by mozahnou          #+#    #+#             */
/*   Updated: 2025/07/02 10:42:47 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	ft_check_unclosed_quotes(char *str)
{
	int		i;
	char	quote_char;

	if (!str)
		return (0);
	i = 0;
	quote_char = 0;
	while (str[i])
	{
		if (!quote_char && (str[i] == '\'' || str[i] == '"'))
		{
			quote_char = str[i];
		}
		else if (quote_char && str[i] == quote_char)
		{
			quote_char = 0;
		}
		i++;
	}
	return (quote_char);
}

char	*ft_handle_quotes(char *str)
{
	char	*result;
	int		i;
	int		j;
	char	quote_char;

	if (!str)
		return (NULL);
	result = malloc(ft_strlen(str) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	quote_char = 0;
	while (str[i])
	{
		if (!quote_char && (str[i] == '\'' || str[i] == '"'))
		{
			quote_char = str[i];
			i++;
			continue ;
		}
		if (quote_char && str[i] == quote_char)
		{
			quote_char = 0;
			i++;
			continue ;
		}
		result[j++] = str[i++];
	}
	result[j] = '\0';
	return (result);
}
