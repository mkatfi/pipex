/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:23:30 by mkatfi            #+#    #+#             */
/*   Updated: 2023/05/05 16:16:01 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

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

void	child1(int f1, char **av, int *pip, char **env)
{
	t_llist	p;

	p.cmd = av[2];
	p.ptr = ft_split(env[get_path(env)] + 5, ':');
	p.id = fork();
	if (p.id == -1)
	{
		perror("fork ");
		exit(1);
	}
	if (p.id == 0)
	{
		p.cmd1 = ft_split(p.cmd, ' ');
		p.path1 = get_cmd(p.ptr, p.cmd1[0]);
		open_file1(f1, av[1], pip);
		execve(p.path1, p.cmd1, env);
		perror("execve: ");
		exit(1);
	}
	freepath(p.ptr);
}

void	child2(int f2, char **av, int *pip, char **env)
{
	int		id;
	char	*path2;
	char	**cmd2;
	char	*cmd;
	char	**ptr;

	cmd = av[3];
	ptr = ft_split(env[get_path(env)] + 5, ':');
	id = fork();
	if (id == 0)
	{
		cmd2 = ft_split(cmd, ' ');
		path2 = get_cmd(ptr, cmd2[0]);
		open_file2(f2, av[4], pip);
		execve(path2, cmd2, env);
		perror("execve: ");
		exit(1);
	}
	close(pip[0]);
	close(pip[1]);
	freepath(ptr);
}

int	main(int ac, char **av, char **env)
{
	int	f2;
	int	f1;
	int	pip[2];

	f1 = 0;
	f2 = 0;
	if (ac != 5)
		ft_error("Error\n");
	pipe(pip);
	child1(f1, av, pip, env);
	child2(f2, av, pip, env);
	while (wait(NULL) != -1)
		;
}
