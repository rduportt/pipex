/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduport <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:26:05 by rduport           #+#    #+#             */
/*   Updated: 2025/02/14 13:16:34 by rduport          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	check(char *dest, const char *src, size_t *len_dest)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = *len_dest;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

size_t	ft_strcat(char *dest, const char *src)
{
	size_t	len_dest;
	size_t	len_src;

	len_dest = 0;
	len_src = 0;
	while (dest[len_dest] != '\0')
		len_dest++;
	while (src[len_src] != '\0')
		len_src++;
	check(dest, src, &len_dest);
	return (len_dest + len_src);
}

char	*str_dup(const char *src, int start, int i)
{
	char	*tab;
	int		index;

	index = 0;
	tab = (char *)malloc(sizeof(char) * (i - start) + 1);
	if (tab == NULL)
		return (NULL);
	while (start != i)
	{
		tab[index] = src[start];
		index++;
		start++;
	}
	tab[index] = '\0';
	return (tab);
}

char	**split_alloc(const char *s, char c)
{
	int		i;
	int		buffer;
	int		words;
	char	**split;

	buffer = -1;
	words = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c && buffer < 0)
			buffer = i;
		else if (s[i] == c && buffer >= 0)
		{
			words++;
			buffer = -1;
		}
	}
	if (s[i] == '\0' && buffer >= 0)
		words++;
	words++;
	split = malloc(words * sizeof(char *));
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		words;
	int		buffer;

	buffer = -1;
	split = split_alloc(s, c);
	if (split == NULL)
		return (NULL);
	i = -1;
	words = 0;
	while (s[++i])
	{
		if (s[i] != c && buffer < 0)
			buffer = i;
		else if (s[i] == c && buffer >= 0)
		{
			split[words++] = str_dup(s, buffer, i);
			buffer = -1;
		}
	}
	if (s[i] == '\0' && buffer >= 0)
		split[words++] = str_dup(s, buffer, i);
	split[words] = NULL;
	return (split);
}
