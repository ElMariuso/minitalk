/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:39:42 by mthiry            #+#    #+#             */
/*   Updated: 2021/09/22 17:56:19 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	c = (char)c;
	str = (char *)s;
	while (n)
	{
		if (*str == c)
			return ((void *)str);
		str++;
		n--;
	}
	return (0);
}
