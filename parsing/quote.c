/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:17:47 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/23 20:18:12 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built.h"
#include "../includes/parsing.h"

int	count_quote(char *s, int max)
{
	int	i;
	int	quote;

	quote = 0;
	i = 0;
	while (s[i] && i < max)
	{
		if (s[i] == '\'' || s[i] == '\"')
			quote++;
		i++;
	}
	return (quote);
}

int	check_quote(char c, int quote, int *boa)
{
	if (c == '\"')
	{
		if (quote == 1)
		{
			*boa = 0;
			return (0);
		}
		if (quote == 0)
			return (1);
	}
	if (c == '\'')
	{
		if (quote == 2)
			return (0);
		if (quote == 0)
			return (2);
	}
	return (0);
}
