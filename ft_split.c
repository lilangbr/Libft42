/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:02:23 by ebresser          #+#    #+#             */
/*   Updated: 2020/02/20 21:27:06 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**fill(char **array, size_t len, char *st, char cut)
{
	size_t	i;
	size_t	j;
	char	stop;

	i = 0;
	if (len == 1)
		array[0] = NULL;
	while (i < len - 1)
	{
		stop = cut;
		j = 0;
		if (i == len - 2)
			stop = '\0';
		while (st[j] != stop) 
			j++;
		array[i] = (char *)malloc( (j + 1) * sizeof(char));
		if (!array[i])
			return (NULL);
		ft_strlcpy(array[i], st, j + 1); //ver nulo
		st = st + j; 
		while (*st == cut)
			st++;
		i++;
	}
	array[len - 1] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	*ps;
	char	sm[2];
	char	**splited;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	sm[0] = c;
	sm[1] = '\0';
	ps = ft_strtrim(s, sm);
	if (ps)
		size = 2;
	else
		size = 1;
	i = 0;
	while (ps[i])
	{
		if (ps[i] == c)
		{
			while (ps[i + 1] == c)
				i++;
			size++;
		}
		i++;
	}
	splited = (char **)malloc(size * sizeof(char *));
	if (!splited)
		return (NULL);
	if (*ps == '\0')
		splited[0] = NULL;
	else
		splited = fill(splited, size, ps, c);
	return (splited);
}