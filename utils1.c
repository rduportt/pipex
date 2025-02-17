/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduport <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:24:25 by rduport           #+#    #+#             */
/*   Updated: 2025/02/14 14:24:36 by rduport          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;
	size_t	sizesrc;

	i = 0;
	sizesrc = 0;
	while (src[sizesrc])
		sizesrc++;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (sizesrc);
}

int	len_strtok(const char *delim, char *str, int i, int *k)
{
	int	len;
	int	j;

	len = 0;
	j = 0;
	while (str[i] == delim[j])
	{
		while (str[i] == delim[j] && delim[j])
			j++;
		i++;
		j = 0;
	}
	*k = i;
	while (str[i + len] && str[i + len] != delim[j])
	{
		while (delim[j] && str[i + len] != delim[j])
			j++;
		len++;
		j = 0;
	}
	return (len);
}

char	*ft_strtok(char *str, const char *delim)
{
	int		i;
	int		k;
	char	*strtok;
	int		len;

	len = len_strtok(delim, str, 0, &k);
	strtok = malloc((len + 1) * sizeof(char));
	if (!strtok)
		return (NULL);
	i = 0;
	while (i < len)
	{
		strtok[i] = str[k + i];
		i++;
	}
	strtok[i] = '\0';
	return (strtok);
}
