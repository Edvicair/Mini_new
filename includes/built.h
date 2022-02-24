/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 00:27:06 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/24 01:06:44 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_H
# define BUILT_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_msh
{
	char			*line;
	char			*pro;
	char			*cd_now;
	char			*cd_old;
	char			**s;
	char			**env;
	struct s_lst	*cmd;
}					t_msh;

typedef struct s_lst
{
	char			**arg;
	struct s_lst	*next;
}					t_lst;

int		ft_strlen(char *s);
int		ft_strncmp(char const *s1, char const *s2, size_t n);

char	*ft_strdup(char *str, int do_free);
char	**ft_split(char const *s, char c);

void	ft_pwd(t_msh *msh, int place);
void	ft_exc_cd(t_msh *msh, int place);
void	ft_exc_env(t_msh *msh, int place);
void	ft_exc_exit(t_msh *msh, int i);
void	ft_exc_echo(t_msh *msh, int place);
void	ft_free_cmd(t_msh *msh);
void	ft_free_lst(t_lst *lst);
void	ft_exc_export(t_msh *msh, int place);
void	ft_fill_env(t_msh *msh, char **env);
void	ft_exc(t_msh *msh, int place);
void	ft_exc_unset(t_msh *msh, int i, int verif, int place);

void	ft_choose_algo(t_msh *msh);

#endif
