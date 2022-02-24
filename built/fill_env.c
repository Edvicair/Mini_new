/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 00:35:55 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/23 22:42:25 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built.h"

static void	ft_init_env(t_msh *msh)
{
	msh->line = NULL;
	msh->pro = NULL;
	msh->s = NULL;
	msh->cd_now = NULL;
	msh->cd_old = NULL;
	msh->env = NULL;
	msh->cmd = NULL;
}

void	ft_fill_env(t_msh *msh, char **env)
{
	int	line;

	line = 0;
	ft_init_env(msh);
	while (env[line])
		line++;
	line++;
	msh->env = (char **)malloc(sizeof(char *) * line);
	if (!msh->env)
		return ;
	line = 0;
	while (env[line])
	{
		msh->env[line] = ft_strdup(env[line], 0);
		line++;
	}
	msh->env[line] = NULL;
}
