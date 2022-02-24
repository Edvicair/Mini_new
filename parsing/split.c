/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:02:23 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/24 07:36:29 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built.h"
#include "../includes/parsing.h"

char	**malloc_word(char *str, char **s, int *k, int *i, int *j)
{
	int word;

	word = ft_count_word(str);
	while (str[*k] && *i <= word)
	{
		if (str[*k] == ' ' && (count_quote(str, *i) % 2 == 0))
		{
			s[*i][*j] = '\0';
			(*i) = (*i + 1);
			(*k) = (*k + 1);
			if (*i < word)
			{
				s[*i] = (char *)malloc(sizeof(char) * (ft_strlen_bis(&str[*k]) + 2));
				if (!s)
					return (NULL);
			}
			(*j) = 0;
		}
		while (str[*k] == ' ')
			(*k) = (*k + 1);
		if (str[*k])
		{
			s[*i][*j] = str[*k];
			(*j) = (*j + 1);
			(*k) = (*k + 1);
		}
	}
	return (s);
}

char	**split_bis(char *str, char **s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	s = malloc_word(str, s, &k, &i, &j);
	if (str[k - 1] == '\0')	
	{
		s[i][j] = '\0';
		i++;
		s[i] = NULL;
		return (s);
	}
	if (str[k] == '\0' && str[k - 1] != ' ')
	{
		s[i][j] = '\0';
		i++;
	}
	s[i] = NULL;
	return (s);
}

char	**split_space(char *str)
{
	char	**s;
	int		i;
	int		j;
	int		k;
	int		word;

	i = 0;
	j = 0;
	k = 0;
	word = ft_count_word(str);
	s = (char **)malloc(sizeof(char *) * (word + 1));
	if (!s)
		return (NULL);
	s[i] = (char *)malloc(sizeof(char) * (ft_strlen_bis(str) + 2));
	if (!s[i])
		return (NULL);
	if (str[0] == ' ')
		k++;
	s = split_bis(&str[k], s);
	return (s);
}
