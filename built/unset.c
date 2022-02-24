/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:48:08 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/24 00:25:52 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built.h"

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

static void	ft_replace(t_msh *msh, int i)
{
	int		j;
	int		size;
	int		max;
	char	**ret;

	size = 0;
	j = 0;
	while (msh->env[size])
		size++;
	max = size;
	ret = malloc(sizeof(char *) * (size + 1));
	if (!ret)
		return ;
	size = 0;
	while (size < max && msh->env[size])
	{
		if (i == j)
			free(msh->env[size++]);
		if (msh->env[size])
		{
			ret[j] = ft_strdup(msh->env[size], 1);
			j++;
		}
		size++;
	}
	ret[j] = NULL;
	free(msh->env);
	msh->env = ret;
}

void	ft_exc_unset(t_msh *msh, int i, int verif, int place)
{
	int		j;
	int		size;
	t_lst	*cpy;

	size = 0;
	j = 0;
	cpy = msh->cmd;
	while (size < place)
	{
		cpy = cpy->next;
		size++;
	}
	if (!msh->cmd->arg[1])
		return ;
	while (msh->cmd->arg[i] != NULL)
	{
		while (msh->env[j] && verif == 0)
		{
			if (ft_cmp(msh->env[j], msh->cmd->arg[i]) != 0)
				j++;
			else
			{
				ft_replace(msh, j);
				verif = 1;
			}
		}
		i++;
		j = 0;
		verif = 0;
	}
	return ;
}
