/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:57:18 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/23 20:51:37 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

void	ft_lst_first(t_msh *msh);
void	ft_fill_struct(t_msh *msh);
void	ft_lstadd_back(t_lst **alst, t_lst *new);

int		ft_strlen_bis(char *str);
int		ft_count_word(char *str);
int		is_sep(char *str, int i);
int		count_quote(char *s, int max);
int		parsing(t_msh *msg, char **env);
int		check_quote(char c, int quote, int *boa);

char	**ft_strtok(char *str);
char	*ft_strdup_bis(char **str, int max);
char	**split_space(char *str);

t_lst	*ft_lstlast(t_lst *lst);

#endif
