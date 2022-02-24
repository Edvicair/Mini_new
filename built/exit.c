/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 05:01:51 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/23 23:29:16 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built.h"

void	ft_free_lst(t_lst *lst)
{
	t_lst	*cpy;
	int		i;

	cpy = lst;
	i = 0;
	while (lst)
	{
		cpy = lst->next;
		i = 0;
		while (lst->arg[i])
		{
			free(lst->arg[i]);
			i++;
		}
		free(lst->arg);
		free(lst);
		lst = cpy;
	}
}

static void	ft_free_norm(t_msh *msh)
{
	if (msh->line)
		free(msh->line);
	if (msh->pro)
		free(msh->pro);
	if (msh->cd_now)
		free(msh->cd_now);
	if (msh->cd_old)
		free(msh->cd_old);
}

static void	ft_free(t_msh *msh)
{
	int		i;

	i = 0;
	ft_free_norm(msh);
	while (msh->s[i])
	{
		free(msh->s[i]);
		i++;
	}
	if (msh->s)
		free(msh->s);
	i = 0;
	while (msh->env[i])
	{
		free(msh->env[i]);
		i++;
	}
	if (msh->env)
		free(msh->env);
	ft_free_lst(msh->cmd);
}

static int	is_num(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

void	ft_exc_exit(t_msh *msh, int i)
{
	if (i == 0)
	{
		if (msh->cmd->arg[1] != NULL)
		{
			if (!(is_num(msh->cmd->arg[1])))
			{
				write(1, "exit\n", 5);
				write(1, msh->cmd->arg[1], ft_strlen(msh->cmd->arg[1]));
				write(1, ": numeric argument required\n", 28);
				ft_free(msh);
				exit (EXIT_SUCCESS);
			}
		}
		ft_free(msh);
		write(1, "exit\n", 5);
		exit (EXIT_SUCCESS);
	}
}
