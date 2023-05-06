/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:00:19 by mkatfi            #+#    #+#             */
/*   Updated: 2023/04/21 16:00:19 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include "get_next_line.h"

void	freepath(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	child1(int f1, char *cmd, int *pip, char **env)
{
	int		id;
	char	*path1;
	char	**cmd1;
	char	**ptr;

	ptr = ft_split(env[get_path(env)] + 5, ':');
	id = fork();
	if (f1 != -1)
	{
		if (id == 0)
		{
			cmd1 = ft_split(cmd, ' ');
			path1 = get_cmd(ptr, cmd1[0]);
			dup2(f1, 0);
			dup2(pip[1], 1);
			close(pip[0]);
			close(f1);
			execve(path1, cmd1, env);
			perror("execve");
			exit(1);
		}
	}
	freepath(ptr);
}

void	child2(int f2, char *cmd, int *pip, char **env)
{
	int		id;
	char	*path2;
	char	**cmd2;
	char	**ptr;

	ptr = ft_split(env[get_path(env)] + 5, ':');
	id = fork();
	if (f2 != -1)
	{
		if (id == 0)
		{
			cmd2 = ft_split(cmd, ' ');
			path2 = get_cmd(ptr, cmd2[0]);
			dup2(f2, 1);
			dup2(pip[0], 0);
			close(pip[1]);
			close(f2);
			execve(path2, cmd2, env);
		}
	}	
	close(pip[0]);
	close(pip[1]);
	freepath(ptr);
}

int	here_doc(char *av)
{
	char	*line;
	int		pipefd[2];

	pipe(pipefd);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line || (!(ft_strncmp(av, line, ft_strlen(line) - 1))
				&& ft_strlen(av) == ft_strlen(line) - 1))
			break ;
		ft_putstr_fd(line, pipefd[1]);
		free(line);
	}
	free(line);
	close(pipefd[1]);
	return (pipefd[0]);
}
