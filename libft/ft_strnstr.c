/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:26:52 by mthiry            #+#    #+#             */
/*   Updated: 2021/09/22 17:49:48 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)&*haystack);
	while (haystack[i] && len)
	{
		while ((haystack[i] == needle[j]) && len)
		{
			i++;
			j++;
			len--;
			if (needle[j] == '\0')
				return ((char *)&haystack[i - j]);
		}
		len = len + j;
		len--;
		i = i - j;
		j = 0;
		i++;
	}
	return (0);
}
