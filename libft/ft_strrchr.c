/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:22:03 by mthiry            #+#    #+#             */
/*   Updated: 2021/09/22 17:47:16 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*found;
	int		i;

	c = (char)c;
	found = 0;
	i = ft_strlen(s) + 1;
	while (i)
	{
		if (*s == c)
			found = (char *)s;
		s++;
		i--;
	}
	return (found);
}
