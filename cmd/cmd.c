/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 01:04:31 by malbrand          #+#    #+#             */
/*   Updated: 2022/02/24 01:20:10 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/built.h"
#include "../includes/parsing.h"

static char	**ft_getpath(t_msh *msh)
{
	int		i;
	int		j;
	char	**path;

	i = 0;
	j = 0;
	path = NULL;
	while (msh->env[i] != NULL && ft_strncmp("PATH=", msh->env[i], 3) != 0)
		i++;
	if (msh->env[i])
	{
		if (ft_strncmp("PATH=", msh->env[i], 3) == 0)
		{
			j = ft_strlen(msh->env[i]);
			path = ft_split(&msh->env[i][5], ':');
			return (path);
		}
	}
	return (NULL);
}

static char	*ft_add_cmd(char *cmd, char *add)
{
	int		size;
	int		i;
	char	*ret;

	i = 0;
	size = ft_strlen(cmd) + ft_strlen(add) + 2;
	ret = (char *)malloc(sizeof(char) * size);
	if (!ret)
		return (NULL);
	while (cmd[i])
	{
		ret[i] = cmd[i];
		i++;
	}
	free(cmd);
	ret[i] = '/';
	i++;
	size = 0;
	while (add[size])
	{
		ret[i + size] = add[size];
		size++;
	}
	ret[i + size] = '\0';
	return (ret);
}

static void	ft_exec_cmd(char **cmd, int i, char **av, int j)
{
	pid_t	pid;
	int		status;

	pid = 0;
	status = 0;
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid > 0)
		waitpid(pid, &status, 0);
	else
		execve(cmd[i], &av[j], NULL);
}

void	ft_exc(t_msh *msh, int place)
{
	char	**path;
	t_lst	*cpy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cpy = msh->cmd;
	while (i < place)
	{
		cpy = cpy->next;
		i++;
	}
	i = 0;
	path = ft_getpath(msh);
	while (cpy->arg[j])
	{
		while (path[i])
		{
			path[i] = ft_add_cmd(path[i], cpy->arg[j]);
			if ((access(path[i], R_OK) == 0) && (access(path[i], X_OK) == 0))
			{
				ft_exec_cmd(path, i, cpy->arg, j);
				break ;
			}
			i++;
		}
		j++;
	}
	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}
