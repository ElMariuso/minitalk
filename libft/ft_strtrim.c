/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:02:29 by mthiry            #+#    #+#             */
/*   Updated: 2021/09/22 17:48:44 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	b;
	size_t	c;
	char	*newstr;

	if (!s1 || !set)
		return (0);
	b = 0;
	while (s1[b] && ft_strchr(set, s1[b]))
		b++;
	c = ft_strlen(s1 + b);
	if (c)
		while (s1[c + b - 1] != 0 && ft_strchr(set, s1[c + b - 1]) != 0)
			c--;
	newstr = (char *) malloc (c + 1 * sizeof(char));
	if (!newstr)
		return (0);
	ft_strlcpy(newstr, s1 + b, c + 1);
	newstr[c] = '\0';
	return (newstr);
}
