/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:24:50 by mthiry            #+#    #+#             */
/*   Updated: 2021/09/22 17:55:49 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*dest;
	size_t	size;

	size = ft_strlen(s1) + 1;
	dest = malloc (size * sizeof (char));
	if (!dest || !s1)
		return (0);
	return ((char *) ft_memcpy(dest, s1, size));
}
