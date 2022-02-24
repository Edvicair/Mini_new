/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 07:18:13 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/24 00:13:39 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built.h"

void	ft_exc_env(t_msh *msh, int place)
{
	int		i;
	t_lst	*cpy;

	i = 0;
	cpy = msh->cmd;
	if (place != -1)
	{
		while (i < place)
		{
			cpy = cpy->next;
			i++;
		}
		if (cpy->arg[1] != NULL)
		{
			write(1, "with no arg or option\n", 22);
			return ;
		}
	}
		while (msh->env[i])
		{
			write(1, msh->env[i], ft_strlen(msh->env[i]));
			write(1, "\n", 1);
			i++;
		}
}
