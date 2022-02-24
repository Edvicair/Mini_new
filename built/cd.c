/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 05:53:39 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/23 23:37:32 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built.h"

static void	ft_cd_home(char **env)
{
	int		i;
	char	*ret;

	i = 0;
	while (env[i] && ft_strncmp("HOME=", env[i], 3))
		i++;
	if (env[i])
	{
		ret = ft_strdup(&env[i][5], 0);
		chdir(ret);
		if (chdir(ret) == -1)
		{
			write(1, "cd: no such file or directory : ", 32);
			write(1, ret, ft_strlen(ret));
			write(1, "\n", 1);
		}
		if (ret)
			free(ret);
	}
}

static void	ft_cd_old(t_msh *msh)
{
	char	tampon[UCHAR_MAX];

	if (getcwd(tampon, UCHAR_MAX) == NULL)
		return ;
	msh->cd_now = ft_strdup(tampon, 0);
	if (msh->cd_old)
	{
		chdir(msh->cd_old);
		write (1, msh->cd_old, ft_strlen(msh->cd_old));
		write(1, "\n", 1);
		free(msh->cd_old);
	}
	else
	{
		write (1, msh->cd_now, ft_strlen(msh->cd_now));
		write(1, "\n", 1);
	}
	msh->cd_old = ft_strdup(msh->cd_now, 0);
	free(msh->cd_now);
	msh->cd_now = NULL;
}

void	ft_exc_cd(t_msh *msh, int place)
{
	int		i;
	t_lst	*cpy;

	i = 0;
	cpy = msh->cmd;
	while (i < place)
	{
		cpy = cpy->next;
		i++;
	}
	if (!(ft_strncmp(cpy->arg[0], "cd", 1)))
	{
		if (cpy->arg[1] == NULL)
			ft_cd_home(msh->env);
		else if (!(ft_strncmp(cpy->arg[1], "--\0", 2)))
			ft_cd_home(msh->env);
		else if (!(ft_strncmp(cpy->arg[1], "-\0", 1)))
			ft_cd_old(msh);
		else if (chdir(cpy->arg[1]) == -1)
		{
			write(1, "cd: no such file or directory : ", 32);
			write(1, msh->cmd->arg[1], ft_strlen(msh->cmd->arg[1]));
			write(1, "\n", 1);
		}
	}
}
