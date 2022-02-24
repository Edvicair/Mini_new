/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:03:12 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/23 23:32:11 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built.h"

static int	ft_cmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s2[i] && s1[i])
	{
		if (s2[i] == s1[i])
			i++;
		else
			return (-1);
	}
	return (0);
}

static char	*ft_stradd(char *s1, char *s2)
{
	int		i;
	int		j;
	int		size;
	char	*ret;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * size + 1);
	if (!ret)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

static void	ft_oldpwd(t_msh *msh, int i, char *pwd)
{
	free(msh->env[i]);
	msh->env[i] = ft_stradd("OLDPWD=", pwd);
}

static void	ft_replace_pwd(t_msh *msh, char *pwd)
{
	int	i;

	i = 0;
	while (msh->env[i])
	{
		if (ft_cmp(msh->env[i], "OLDPWD=") != 0)
			i++;
		else
		{
			ft_oldpwd(msh, i, pwd);
			return ;
		}
	}
}

void	ft_pwd(t_msh *msh, int place)
{
	t_lst	*cpy;
	int		i;
	char	tampon[UCHAR_MAX];

	i = 0;
	cpy = msh->cmd;
	while (i < place)
	{
		cpy = cpy->next;
		i++;
	}
	if (cpy->arg[1] != NULL)
	{
		write(1, "command not found\n", 18);
		return ;
	}
	if (getcwd(tampon, UCHAR_MAX) == NULL)
		return ;
	ft_replace_pwd(msh, tampon);
	write(1, tampon, ft_strlen(tampon));
	write(1, "\n", 1);
}
