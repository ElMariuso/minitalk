/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:33:17 by mthiry            #+#    #+#             */
/*   Updated: 2022/01/18 14:37:14 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_freestrjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	len;
	char	*result;

	if (!s1 && !s2)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *) malloc (len + 1 * sizeof(char));
	if (!result)
		return (NULL);
	while (s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free((char *)s1);
	return (result);
}
