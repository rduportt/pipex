/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduport <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:24:08 by rduport           #+#    #+#             */
/*   Updated: 2025/02/14 14:24:12 by rduport          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	main(int argc, char **argv)
{
	t_pipe	spipe;

	(void) argc;
	spipe.cmd1 = ft_split(argv[2], ' ');
	spipe.cmd2 = ft_split(argv[3], ' ');
	spipe.word1 = find_path("/bin/", argv[2]);
	spipe.word2 = find_path("/bin/", argv[3]);
	if (pipe(spipe.fd) == -1)
		return (-1);
	spipe.pid1 = fork();
	if (spipe.pid1 < 0)
		return (-2);
	if (pipe1(&spipe, argv) == 1)
		exit(1);
	spipe.pid2 = fork();
	if (spipe.pid2 < 0)
		return (-3);
	if (pipe2(&spipe, argv) == 1)
		exit(1);
	close_pipe(&spipe);
	waitpid(spipe.pid2, NULL, 0);
	waitpid(spipe.pid1, NULL, 0);
	return (0);
}

char	*find_path(const char *path, char *str)
{
	char	*word;
	char	*temp;

	temp = ft_strtok(str, " ");
	word = malloc((ft_strlen(path) + ft_strlen(temp) + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strcpy(word, path);
	ft_strcat(word, temp);
	free(temp);
	return (word);
}

int	pipe1(t_pipe *spipe, char **argv)
{
	if (spipe->pid1 == 0)
	{
		spipe->file1 = open(argv[1], O_RDONLY);
		if (spipe->file1 < 0)
			return (-3);
		dup2(spipe->file1, STDIN_FILENO);
		dup2(spipe->fd[1], STDOUT_FILENO);
		close(spipe->fd[0]);
		close(spipe->fd[1]);
		close(spipe->file1);
		execve(spipe->word1, spipe->cmd1, NULL);
		perror("execve");
		return (1);
	}
	return (0);
}

int	pipe2(t_pipe *spipe, char **argv)
{
	if (spipe->pid2 == 0)
	{
		spipe->file2 = open(argv[4], O_WRONLY);
		if (spipe->file2 < 0)
			return (-4);
		dup2(spipe->file2, STDOUT_FILENO);
		dup2(spipe->fd[0], STDIN_FILENO);
		close(spipe->fd[0]);
		close(spipe->fd[1]);
		close(spipe->file2);
		execve(spipe->word2, spipe->cmd2, NULL);
		perror("execve");
		return (1);
	}
	return (0);
}

void	close_pipe(t_pipe *spipe)
{
	int	i;

	i = 0;
	while (spipe->cmd1[i])
		free(spipe->cmd1[i++]);
	free(spipe->cmd1);
	i = 0;
	while (spipe->cmd2[i])
		free(spipe->cmd2[i++]);
	free(spipe->cmd2);
	close(spipe->fd[0]);
	close(spipe->fd[1]);
	free(spipe->word1);
	free(spipe->word2);
}
