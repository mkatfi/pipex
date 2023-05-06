/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:19:54 by mkatfi            #+#    #+#             */
/*   Updated: 2023/05/04 17:55:41 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct f_list {
	int		id;
	char	*path1;
	char	**cmd1;
	char	*cmd;
	char	**ptr;

}	t_llist;

size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	ft_error(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		get_path(char **envp);
char	*get_cmd(char **ptr, char *cmd);
void	child2(int f2, char **av, int *pip, char **env);
void	freepath(char **ptr);
void	open_file1(int f1, char *av, int *pip);
void	open_file2(int f2, char *av, int *pip);

#endif