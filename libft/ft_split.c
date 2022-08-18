/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:47:50 by mthiry            #+#    #+#             */
/*   Updated: 2021/09/22 17:56:11 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_row(char const *s, char c)
{
	int	i;
	int	row;

	i = 0;
	row = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			row++;
			while (s[i] != c && s[i])
				i++;
		}
		i++;
	}
	return (row);
}

static int	get_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static char	**free_errors(char **strarray)
{
	int	i;

	i = 0;
	while (strarray[i])
	{
		free(strarray[i]);
		i++;
	}
	free(strarray);
	return (0);
}

static char	**fill_array(char const *s, char **strarray, char c, int row)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] && j < row)
	{
		k = 0;
		while (s[i] == c)
			i++;
		strarray[j] = (char *) malloc (get_len(s, c, i) + 1 * sizeof(char));
		if (!strarray[j])
			return (free_errors(strarray));
		while (s[i] && s[i] != c)
			strarray[j][k++] = s[i++];
		strarray[j][k] = '\0';
		j++;
	}
	strarray[j] = 0;
	return (strarray);
}

char	**ft_split(char const *s, char c)
{
	int		row;
	char	**strarray;

	if (!s)
		return (0);
	row = get_row(s, c);
	strarray = (char **) ft_calloc (row + 1, sizeof(char *));
	if (!strarray)
		return (0);
	strarray = fill_array(s, strarray, c, row);
	return (strarray);
}
