/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:20:48 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/23 22:21:24 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built.h"
#include "../includes/parsing.h"

int	is_sep(char *str, int i)
{
	if ((str[i] == '|' || str[i] == ';') && (count_quote(str, i) % 2) == 0)
		return (1);
	return (0);
}

static void	ft_strdup_norm(char **s, char **str, int i, int max)
{
	int		j;

	j = 0;
	while (str[0][i] && i < max)
	{
		while (str[0][i] == '|')
		{
			i++;
			while (str[0][i] == ' ')
				i++;
		}
		if (str[0][i])
		{
			(*s)[j] = str[0][i];
			i++;
			j++;
		}
	}
	(*s)[j] = '\0';
	*str = ft_strdup(&str[0][i], 0);
}

char	*ft_strdup_bis(char **str, int max)
{
	int			i;
	char		*s;

	i = 0;
	if (str[0][i] == '|')
	{
		i++;
		while (str[0][i] == ' ')
			i++;
		s = malloc(sizeof(char) * (max - i) + 1);
	}
	else
		s = malloc(sizeof(char) * (max + 1));
	if (!s)
		return (0);
	if (str[0][i] && i < max)
	{
		ft_strdup_norm(&s, str, i, max);
		return (s);
	}
	s[0] = '\0';
	*str = ft_strdup(&str[0][i], 0);
	return (s);
}

int	ft_count_word(char *str)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] == ' ' && i != 0 && str[i - 1] != ' '
			&& (count_quote(str, i) % 2) == 0)
			word++;
		i++;
	}
	if (str[i] == '\0' && str[i - 1] != ' ')
	{
		word++;
		return (word);
	}
	if (str[i - 1] != ' ' && str[i] == '\0')
		word++;
	return (word);
}

int	ft_strlen_bis(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != ' ' || (count_quote(str, i) % 2)))
		i++;
	if (str[0] == ' ')
		i--;
	return (i);
}
