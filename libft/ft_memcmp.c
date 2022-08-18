/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:55:26 by mthiry            #+#    #+#             */
/*   Updated: 2021/09/22 17:46:21 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	result;

	while (n)
	{
		result = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		if (result)
			return (result);
		n--;
	}
	return (0);
}
