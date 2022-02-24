/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_inf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:31:26 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/23 22:42:20 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built.h"
#include "../includes/parsing.h"

char	*ft_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (ft_strdup(&line[i], 0));
}

void	ft_fill_struct(t_msh *msh)
{
	int		i;
	t_lst	*add;

	i = 0;
	msh->pro = ft_space(msh->line);
	msh->s = ft_strtok(msh->pro);
	msh->cmd = malloc(sizeof(t_lst));
	if (!msh->cmd)
		return ;
	msh->cmd->arg = split_space(msh->s[i]);
	msh->cmd->next = NULL;
	while (msh->s[++i])
	{
		add = malloc(sizeof(t_lst));
		if (!add)
			return ;
		if (msh->s[i][0])
		{
			add->arg = split_space(msh->s[i]);
			add->next = NULL;
			ft_lstadd_back(&msh->cmd, add);
		}
	}
}
