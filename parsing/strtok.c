/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:01:38 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/24 07:16:35 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built.h"
#include "../includes/parsing.h"

char	**ft_cut_bis(char *str, char **s, int *i, int *j)
{
	if ((is_sep(str, *i) && *i != 0))
	{
		while (str[*i] == ' ')
			(*i) = (*i + 1);
		s[*j] = ft_strdup_bis(&str, *i);
		(*j) = (*j + 1);
		(*i) = 0;
	}
	return (s);
}

char	**ft_cut_sep(char *str, char **s, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	s = (char **)malloc(sizeof(char *) * (len + 2));
	if (!s)
		return (NULL);
	while (str[i])
	{
		s = ft_cut_bis(str, s, &i, &j);
		i++;
	}
	if (str[i] == '\0' && ft_strlen(str) > 0)
	{
		s[j] = ft_strdup_bis(&str, i);
		j++;
	}
	s[j] = NULL;
	if (str)
		free(str);
	return (s);
}

char	**ft_strtok(char *str)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	j = 0;
	s = NULL;
	while (str[i])
	{
		if ((is_sep(str, i) && i != 0))
			j++;
		i++;
	}
	if (str[i] == '\0' && (str[i - 1] != ';' && str[i - 1] != '|'))
		j++;
	s = ft_cut_sep(str, s, j);
	return (s);
}
