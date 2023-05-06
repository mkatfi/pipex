/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:55:38 by mkatfi            #+#    #+#             */
/*   Updated: 2023/04/20 18:46:33 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_error(char *s)
{
	write(2, s, ft_strlen(s));
	exit(1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*g;

	if (!s1 || !s2)
		return (NULL);
	k = ft_strlen(s1);
	l = ft_strlen(s2);
	g = malloc(sizeof(char) * (k + l) + 1);
	if (!g)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		g[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		g[i++] = s2[j++];
	g[i] = '\0';
	return (g);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}	
	return (0);
}

int	get_path(char **envp)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (envp[i])
		i++;
	while (k < i)
	{
		if (ft_strncmp(envp[k], "PATH", 4) == 0)
			return (k);
		k++;
	}
	return (0);
}

char	*get_cmd(char **path, char *cmd)
{
	int		i;
	int		fd;
	char	*path_cmd;
	char	*tmp;

	fd = access(cmd, X_OK);
	if (fd != -1)
		return (cmd);
	path_cmd = ft_strjoin("/", cmd);
	i = 0;
	while (path[i++])
	{
		tmp = ft_strjoin(path[i], path_cmd);
		fd = access(tmp, X_OK);
		if (fd != -1)
		{
			free(path_cmd);
			return (tmp);
		}
		close(fd);
		free(tmp);
	}
	free(path_cmd);
	ft_error("Command not found\n");
	return (NULL);
}
