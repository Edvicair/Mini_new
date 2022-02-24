/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:05:49 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/23 20:16:18 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built.h"
#include "../includes/parsing.h"

int	ft_count_lst(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_lst	*ft_lstlast(t_lst *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_lst **alst, t_lst *new)
{
	t_lst	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}
