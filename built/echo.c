/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:08:27 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/24 00:44:10 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built.h"

void	ft_exc_echo(t_msh *msh, int place)
{
	int		i;
	int		j;
	t_lst	*cpy;

	i = 0;
	j = 1;
	cpy = msh->cmd;
	while (i < place)
	{
		cpy = cpy->next;
		i++;
	}
	if (cpy->arg[j] == NULL)
		write(1, "\n", 2);
	else if (ft_strncmp(cpy->arg[j], "-n", 0) == 0)
	{
		j++;
		while (cpy->arg[j])
		{
			write(1, cpy->arg[j], ft_strlen(cpy->arg[j]));
			if (cpy->arg[j + 1] != NULL)
				write(1, " ", 1);
			j++;
		}
	}
	else
	{
		while (cpy->arg[j])
		{
			write(1, cpy->arg[j], ft_strlen(cpy->arg[j]));
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
	}
}
