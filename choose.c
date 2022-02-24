/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:53:37 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/24 01:01:51 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/built.h"
#include "includes/parsing.h"

void	ft_free_cmd(t_msh *msh)
{
	int		i;

	i = 0;
	if (msh->line)
		free(msh->line);
	if (msh->pro)
		free(msh->pro);
	while (msh->s[i])
	{
		free(msh->s[i]);
		i++;
	}
	if (msh->s)
		free(msh->s);
	ft_free_lst(msh->cmd);
}

void	ft_choose_algo(t_msh *msh)
{
	int		i;
	t_lst	*cpy;

	ft_fill_struct(msh);
	i = 0;
	cpy = msh->cmd;
	while (cpy)
	{
		if (!(ft_strncmp(cpy->arg[0], "exit\0", ft_strlen(cpy->arg[0]))))
			ft_exc_exit(msh, i);
		else if (!(ft_strncmp(cpy->arg[0], "pwd\0", ft_strlen(cpy->arg[0]))))
			ft_pwd(msh, i);
		else if (!(ft_strncmp(cpy->arg[0], "cd\0", ft_strlen(cpy->arg[0]))))
			ft_exc_cd(msh, i);
		else if (!(ft_strncmp(cpy->arg[0], "env\0", ft_strlen(cpy->arg[0]))))
			ft_exc_env(msh, i);
		else if (!(ft_strncmp(cpy->arg[0], "export\0", ft_strlen(cpy->arg[0]))))
			ft_exc_export(msh, i);
		else if (!(ft_strncmp(cpy->arg[0], "unset\0", ft_strlen(cpy->arg[0]))))
			ft_exc_unset(msh, 1, 0, i);
		else if (!(ft_strncmp(cpy->arg[0], "echo\0", ft_strlen(cpy->arg[0]))))
			ft_exc_echo(msh, i);
		else
			ft_exc(msh, i);
		cpy = cpy->next;
		i++;
	}
	ft_free_cmd(msh);
}
