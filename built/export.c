/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:29:56 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/24 00:22:55 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built.h"

static char	*ft_search_name(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (str[i] != '=' && str[i])
		i++;
	if (str[i] == '=')
	{
		ret = (char *)malloc(sizeof(char) * (i + 2));
		if (!ret)
			return (NULL);
		while (j <= i)
		{
			ret[j] = str[j];
			j++;
		}
		ret[j] = '\0';
		return (ret);
	}
	return (NULL);
}

static int	ft_cmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s2[i] && s1[i])
	{
		if (s2[i] == s1[i])
			i++;
		else
			return (-1);
	}
	return (0);
}

static void	ft_replace(t_msh *msh, int i, char *str)
{
	if (msh->env[i])
	{
		free(msh->env[i]);
		msh->env[i] = ft_strdup(str, 0);
	}
}

void	ft_exc_export(t_msh *msh, int place)
{
	int		i;
	int		j;
	char	*name;
	int		size;
	t_lst	*cpy;

	j = 0;
	i = 1;
	size = 0;
	cpy = msh->cmd;
	while (size < place)
	{
		cpy = cpy->next;
		size++;
	}
	if (cpy->arg[1] == NULL)
		ft_exc_env(msh, -1);
	else
	{
		while (cpy->arg[i] != NULL)
		{
			name = ft_search_name(cpy->arg[i]);
			if (name)
			{
				while (ft_cmp(name, msh->env[j]))
					j++;
				free(name);
				ft_replace(msh, j, cpy->arg[i]);
			}
			j = 0;
			i++;
		}
	}
}
