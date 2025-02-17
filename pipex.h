/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduport <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:28:21 by rduport           #+#    #+#             */
/*   Updated: 2025/02/14 14:28:23 by rduport          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_pipe
{
	int		fd[2];
	int		pid1;
	int		pid2;
	int		file1;
	int		file2;
	char	**cmd1;
	char	**cmd2;
	char	*word1;
	char	*word2;
}t_pipe;

int		pipe1(t_pipe *spipe, char **argv);
int		pipe2(t_pipe *spipe, char **argv);
void	close_pipe(t_pipe *spipe);
char	*find_path(const char *path, char *str);
void	check(char *dest, const char *src, size_t *len_dest);
size_t	ft_strcat(char *dest, const char *src);
char	*str_dup(const char *src, int start, int i);
char	**split_alloc(const char *s, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *string);
size_t	ft_strcpy(char *dst, const char *src);
int		len_strtok(const char *delim, char *str, int i, int *k);
char	*ft_strtok(char *str, const char *delim);

#endif
