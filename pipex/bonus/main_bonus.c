/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:50:44 by mkatfi            #+#    #+#             */
/*   Updated: 2023/05/06 00:40:33 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	mult_pipex_continue(t_list p, int *pip, char **env)
{
	dup2(pip[0], 0);
	dup2(p.pip_2[1], 1);
	close(p.pip_2[0]);
	execve(p.path2, p.cmd2, env);
	perror("execve: ");
	exit(1);
}

void	mult_pipex1(int ac, char **av, int *pip, char **env)
{
	t_list	p;

	p.j = ac - 3;
	p.i = 3;
	while (p.i <= p.j)
	{
		pipe(p.pip_2);
		p.ptr = ft_split(env[get_path(env)] + 5, ':');
		p.id = fork();
		if (p.id == 0)
		{
			p.cmd2 = ft_split(av[p.i], ' ');
			p.path2 = get_cmd(p.ptr, p.cmd2[0]);
			mult_pipex_continue(p, pip, env);
		}
		close(p.pip_2[1]);
		*pip = *p.pip_2;
		freepath(p.ptr);
		p.i++;
	}
}

void	mult_pipex(int ac, char **av, int *pip, char **env)
{
	t_list	p;

	p.f1 = open(av[1], O_RDONLY);
	if (p.f1 < 0)
		ft_error("no such file or directory\n");
	p.last_fd = pip[0];
	child1(p.f1, av[2], pip, env);
	close(pip[1]);
	mult_pipex1(ac, av, pip, env);
	p.f2 = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	child2(p.f2, av[ac - 2], pip, env);
}

int	main(int ac, char **av, char **env)
{
	int		pip[2];
	t_list	data;

	data.str = "here_doc";
	data.fp = 0;
	if (ac >= 5)
	{
		pipe(pip);
		if (ac == 6 && (ft_strncmp(av[1], data.str, ft_strlen(data.str)) == 0))
		{
			data.fp = here_doc(av[2]);
			pipe(pip);
			child1(data.fp, av[3], pip, env);
			data.f2 = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
			child2(data.f2, av[ac - 2], pip, env);
		}
		else if (ac >= 5)
			mult_pipex(ac, av, pip, env);
	}
	while (wait(NULL) != -1)
		;
}
