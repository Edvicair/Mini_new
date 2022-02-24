/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 00:25:57 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/23 23:18:05 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/built.h"

#define PROMPT "EL SHELLO $ "

static void	ft_newline(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	main(int ac, char **av, char **env)
{
	t_msh	msh;

	(void)ac;
	(void)av;
	ft_fill_env(&msh, env);
	signal(SIGINT, ft_newline);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		msh.line = readline(PROMPT);
		if (!msh.line || !msh.line[0])
		{
			write(1, "exit", 4);
			break ;
		}
		add_history(msh.line);
		ft_choose_algo(&msh);
	}
	return (0);
}
