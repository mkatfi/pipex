/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:59:10 by mkatfi            #+#    #+#             */
/*   Updated: 2023/05/04 17:57:10 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "get_next_line.h"

typedef struct s_list {
	int		f2;
	int		f1;
	int		id;
	char	*path2;
	char	**cmd2;
	char	**ptr;
	int		i;
	int		j;
	int		last_fd;
	int		pip_2[2];
	int		fp;
	char	*str;
}t_list;

size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	ft_error(char *s);
int		get_path(char **env);
char	*get_cmd(char **ptr, char *cmd);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	freepath(char **ptr);
int		here_doc(char *exit);
void	ft_putstr_fd(char *s, int fd);
void	child1(int f1, char *cmd, int *pip, char **env);
void	child2(int f2, char *cmd, int *pip, char **env);
#endif