/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 01:13:22 by mkatfi            #+#    #+#             */
/*   Updated: 2023/05/05 00:13:18 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	open_file1(int f1, char *av, int *pip)
{
	f1 = open(av, O_RDONLY);
	if (f1 < 0)
	{
		perror("open ");
		exit(1);
	}
	dup2(f1, 0);
	dup2(pip[1], 1);
	close(pip[0]);
	close(f1);
}

void	open_file2(int f2, char *av, int *pip)
{
	f2 = open(av, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f2 < 0)
	{
		perror("open ");
		exit(1);
	}
	dup2(pip[0], 0);
	dup2(f2, 1);
	close(pip[1]);
	close(f2);
}
